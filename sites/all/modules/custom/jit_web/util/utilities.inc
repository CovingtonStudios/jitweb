<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Common Functions
 */

function jit_web_delete_view($view_name){
    $view = views_get_view($view_name);

    $view->delete();
}

function jit_web_update_nodetype_variables($content_type){
        $type = $content_type->type;
    if(method_exists($content_type,'get_variable_settings_array')){

        $options = $content_type->get_variable_settings_array();

    }else{
        //create generic JITNode to grab the default settings

        $object = new JITNodeType($type);

        $options = $object->get_variable_settings_array();
    }

    foreach($options as $index => $option){
            variable_set($index.'_'.$type,$option);
        }


}

function jit_web_get_panel_settings($active_only = TRUE,$fetchby = 'section_code'){

  $query = db_select('jit_settings_sections','s');

  $query -> join('jit_settings_panels','p','s.panel_name = p.panel_name');

  $query ->fields('s', array('section_code','section_name','panel_name'));

    if($active_only){
      $query ->condition('p.status',1,'=');
    }

  $results = $query->execute()->fetchAllAssoc($fetchby);

  return $results;
}

function jit_web_get_tid_from_taxonomy_term_name($term_name, $vocabulary){
        $vid = taxonomy_vocabulary_machine_name_load($vocabulary)->vid;

        $query = new EntityFieldQuery;
        $result = $query
        ->entityCondition('entity_type', 'taxonomy_term')
        ->propertyCondition('name', $term_name)
        ->propertyCondition('vid', $vid) // 4 == Vid of the known vocabulary.
        ->execute();

        if(count($result)>0){
        //Extract the Tid from the results.
        $tid = array_shift($result['taxonomy_term'])->tid;

        return $tid;
        }else{
            return FALSE;
        }

}

function jit_web_get_field_value_array($value, $column_name = 'value', $position = 0, $language = LANGUAGE_NONE){
    return array(
      $language => array(
        $position => array(
          $column_name => $value,
        ),
      ),
    );
}

function jit_web_load_classes(){
    $path = drupal_get_path('module', 'jit_web').'/classes' ;
    $ext = 'class';
    $files = file_scan_directory($path, '/.*\.'.$ext.'$/');

    foreach($files as $filepath =>$file){
        require_once $filepath;
    }
}

function jit_web_get_sections(){
    $jitproduct_sections = &drupal_static(__FUNCTION__);
    if (!isset($sections)){
        $jitproduct_sections = db_select('jit_settings_sections','s')
            ->fields('s',array('section_code','section_name','panel_name','weight'))
            ->execute()
            ->fetchAllAssoc('section_code');
    }

    return $jitproduct_sections;

}

/*
 * Check if field exists and is not deleted in field_config table
 */

function jit_web_field_exists($field_name){
    $query = db_select('field_config','fc')
        ->fields('fc', array('id','field_name'))
        ->condition('field_name',$field_name,'=')
        ->condition('deleted',0,'=')
        ->execute()
        ->fetchAllKeyed(0);

    if (count($query)>0){
        return TRUE;
    }else{
        return FALSE;
    }

}

function jit_web_instance_exists($info,$entity_type){
    $exists = field_info_instance($entity_type, $info['field_name'], $info['bundle']);

    if(isset($exists)){
        return TRUE;
    }
    return FALSE;


}

function jit_web_field_get_jit_type_by_id($fid){
    $query = db_select('jit_settings_fields', 'f')
            ->fields('f',array('fid','type'))
            ->condition('fid', $fid, '=')
            ->execute()
            ->fetchAllKeyed(0, 1);
    if (count($query)>0){
        return $query[$fid];
    }else{
        return 'na';
    }
}


/**
 * Functions for Updated Database custom fields
 */

function jit_web_update_nodetype_sections($sections,$showmessage = TRUE){
    global $user;

    foreach($sections as $section){
        $section_name = $section['section_name'];
        $dbmergeresult = db_merge('jit_settings_nodetype_sections')
            ->key(array('node_type' => $section['node_type'],'section_code'=>$section['section_code']))
            ->fields(array(
              'node_type'=>$section['node_type'],
              'section_name'=>$section_name,
              'section_code'=>$section['section_code'],
              'modifiedby'=> $user->name,
            ))
            ->execute();

            if($showmessage){
                    $merge_message = '';

                    switch ($dbmergeresult) {
                        case 1:
                          $merge_message = 'Insert JIT Products custom name for section <i>'.$section_name.'</i> type <i>'.$section['node_type'].'</i> completed.';
                          $message_type = 'status';
                          break;
                        case 2:
                          $merge_message = 'Update JIT Products custom name for section <i>'.$section_name.'</i> type <i>'.$section['node_type'].'</i> completed.';
                          $message_type = 'status';
                          break;
                        Default:
                          $merge_message = 'Save operation for JIT Products custom name for section <i>'.$section_name.'</i> type <i>'.$section['node_type'].'</i> failed.';
                          $message_type = 'error';
                          break;
                    }

                    drupal_set_message($merge_message, $message_type);
            }
    }
}

function jit_web_update_fields($field, $showmessage = TRUE){
    global $user;
    $field_name = $field['field_name'];
    $dbmergeresult = db_merge('jit_settings_fields')
        ->key(array('fid' => $field['fid']))
        ->fields(array(
          'fid'=>$field['fid'],
          'type'=>$field['jit_type'],
          'field_name'=>$field['field_machine_name'],
          'modifiedby'=> $user->name,
        ))
        ->execute();

    if($showmessage){

        $merge_message = '';


        switch ($dbmergeresult) {
            case 1:
              $merge_message = 'Insert JIT Products Field settings for <i>'.$field_name.'</i> completed.';
              $message_type = 'status';
              break;
            case 2:
              $merge_message = 'Update JIT Products Field settings for <i>'.$field_name.'</i> completed.';
              $message_type = 'status';
              break;
            Default:
              $merge_message = 'Save operation for JIT Products Field settings for <i>'.$field_name.'</i> failed.';
              $message_type = 'error';
              break;
        }

        drupal_set_message($merge_message, $message_type);
    }
}

function jit_web_get_allowed_icon_sizes(){
    return array(
        '' => '1x',
        'jit-stack-1-7x' => '1.7x',
        'jit-stack-2x' => '2x',
        'jit-stack-4x' => '4x',
    );
}

function jit_web_get_allowed_icon_colors(){
    return array(

        'jit-primary' => 'jit-primary',
        'jit-secondary' => 'jit-secondary',
        'jit-tertiary' => 'jit-tertiary',
        'jit-quaternary' => 'jit-quaternary',
        'text-muted' => 'text-muted',
        'text-primary' => 'text-primary',
        'text-success' => 'text-success',
        'text-info' => 'text-info',
        'text-warning' => 'text-warning',
        'text-danger' => 'text-danger',

    );
}

function jit_web_get_allowed_icons(){
    return array(
        'jit-book' => 'JIT book',
        'jit-check-stackable' => 'JIT check (for stacking)',
        'jit-desktop' => 'JIT desktop',
        'jit-envelope' => 'JIT envelope',
        'jit-home' => 'JIT home',
        'jit-money' => 'JIT money',
        'jit-sitemap' => 'JIT sitemap',
        'jit-tablet' => 'JIT tablet',
        'jit-globe-stackable' => 'JIT globe (for stacking)',
        'jit-dinrail' => 'JIT dinrail',
        'jit-image' => 'JIT image',
        'jit-photo' => 'JIT photo',
        'jit-picture-o' => 'JIT picture',
        'jit-hdd-o' => 'JIT hdd',
        'jit-file-pdf-o' => 'JIT file pdf',
        'jit-file-word-o' => 'JIT file word',
        'jit-file-excel-o' => 'JIT file excel',
        'jit-file-powerpoint-o' => 'JIT file powerpoint',
        'jit-file-image-o' => 'JIT file image',
        'jit-file-photo-o' => 'JIT file photo',
        'jit-file-picture-o' => 'JIT file picture',
        'jit-file-archive-o' => 'JIT file archive',
        'jit-file-zip-o' => 'JIT file zip',
        'jit-file-audio-o' => 'JIT file audio',
        'jit-file-sound-o' => 'JIT file sound',
        'jit-file-movie-o' => 'JIT file movie',
        'jit-file-video-o' => 'JIT file video',
        'glyphicon-asterisk' => 'asterisk',
        'glyphicon-plus' => 'plus',
        'glyphicon-euro' => 'euro',
        'glyphicon-eur' => 'eur',
        'glyphicon-minus' => 'minus',
        'glyphicon-cloud' => 'cloud',
        'glyphicon-envelope' => 'envelope',
        'glyphicon-pencil' => 'pencil',
        'glyphicon-glass' => 'glass',
        'glyphicon-music' => 'music',
        'glyphicon-search' => 'search',
        'glyphicon-heart' => 'heart',
        'glyphicon-star' => 'star',
        'glyphicon-star-empty' => 'empty',
        'glyphicon-user' => 'user',
        'glyphicon-film' => 'film',
        'glyphicon-th-large' => 'large',
        'glyphicon-th' => 'th',
        'glyphicon-th-list' => 'th-list',
        'glyphicon-ok' => 'ok',
        'glyphicon-remove' => 'remove',
        'glyphicon-zoom-in' => 'in',
        'glyphicon-zoom-out' => 'out',
        'glyphicon-off' => 'off',
        'glyphicon-signal' => 'signal',
        'glyphicon-cog' => 'cog',
        'glyphicon-trash' => 'trash',
        'glyphicon-home' => 'home',
        'glyphicon-file' => 'file',
        'glyphicon-time' => 'time',
        'glyphicon-road' => 'road',
        'glyphicon-download-alt' => 'alt',
        'glyphicon-download' => 'download',
        'glyphicon-upload' => 'upload',
        'glyphicon-inbox' => 'inbox',
        'glyphicon-play-circle' => 'play-circle',
        'glyphicon-repeat' => 'repeat',
        'glyphicon-refresh' => 'refresh',
        'glyphicon-list-alt' => 'list-alt',
        'glyphicon-lock' => 'lock',
        'glyphicon-flag' => 'flag',
        'glyphicon-headphones' => 'headphones',
        'glyphicon-volume-off' => 'Volume off',
        'glyphicon-volume-down' => 'Volume down',
        'glyphicon-volume-up' => 'Volume up',
        'glyphicon-qrcode' => 'qrcode',
        'glyphicon-barcode' => 'barcode',
        'glyphicon-tag' => 'tag',
        'glyphicon-tags' => 'tags',
        'glyphicon-book' => 'book',
        'glyphicon-bookmark' => 'bookmark',
        'glyphicon-print' => 'print',
        'glyphicon-camera' => 'camera',
        'glyphicon-font' => 'font',
        'glyphicon-bold' => 'bold',
        'glyphicon-italic' => 'italic',
        'glyphicon-text-height' => 'height',
        'glyphicon-text-width' => 'width',
        'glyphicon-align-left' => 'left',
        'glyphicon-align-center' => 'center',
        'glyphicon-align-right' => 'right',
        'glyphicon-align-justify' => 'justify',
        'glyphicon-list' => 'list',
        'glyphicon-indent-left' => 'indent left',
        'glyphicon-indent-right' => 'indent right',
        'glyphicon-facetime-video' => 'video',
        'glyphicon-picture' => 'picture',
        'glyphicon-map-marker' => 'map marker',
        'glyphicon-adjust' => 'adjust',
        'glyphicon-tint' => 'tint',
        'glyphicon-edit' => 'edit',
        'glyphicon-share' => 'share',
        'glyphicon-check' => 'check',
        'glyphicon-move' => 'move',
        'glyphicon-step-backward' => 'step backward',
        'glyphicon-fast-backward' => 'fast backward',
        'glyphicon-backward' => 'backward',
        'glyphicon-play' => 'play',
        'glyphicon-pause' => 'pause',
        'glyphicon-stop' => 'stop',
        'glyphicon-forward' => 'forward',
        'glyphicon-fast-forward' => 'fast forward',
        'glyphicon-step-forward' => 'step forward',
        'glyphicon-eject' => 'eject',
        'glyphicon-chevron-left' => 'chevron left',
        'glyphicon-chevron-right' => 'chenron right',
        'glyphicon-plus-sign' => 'plus sign',
        'glyphicon-minus-sign' => 'minus sign',
        'glyphicon-remove-sign' => 'remove sign',
        'glyphicon-ok-sign' => 'ok sign',
        'glyphicon-question-sign' => 'question sign',
        'glyphicon-info-sign' => 'info sign',
        'glyphicon-screenshot' => 'screenshot',
        'glyphicon-remove-circle' => 'remove circle',
        'glyphicon-ok-circle' => 'ok circle',
        'glyphicon-ban-circle' => 'ban circle',
        'glyphicon-arrow-left' => 'arrow left',
        'glyphicon-arrow-right' => 'arrow right',
        'glyphicon-arrow-up' => 'arrow up',
        'glyphicon-arrow-down' => 'arrow down',
        'glyphicon-share-alt' => 'share-alt',
        'glyphicon-resize-full' => 'resize full',
        'glyphicon-resize-small' => 'resize small',
        'glyphicon-exclamation-sign' => 'exclamation sign',
        'glyphicon-gift' => 'gift',
        'glyphicon-leaf' => 'leaf',
        'glyphicon-fire' => 'fire',
        'glyphicon-eye-open' => 'eye open',
        'glyphicon-eye-close' => 'eye close',
        'glyphicon-warning-sign' => 'warning sign',
        'glyphicon-plane' => 'plane',
        'glyphicon-calendar' => 'calendar',
        'glyphicon-random' => 'random',
        'glyphicon-comment' => 'comment',
        'glyphicon-magnet' => 'magnet',
        'glyphicon-chevron-up' => 'chevron up',
        'glyphicon-chevron-down' => 'chevron down',
        'glyphicon-retweet' => 'retweet',
        'glyphicon-shopping-cart' => 'shopping cart',
        'glyphicon-folder-close' => 'folder close',
        'glyphicon-folder-open' => 'folder open',
        'glyphicon-resize-vertical' => 'resize vertical',
        'glyphicon-resize-horizontal' => 'resize horizontal',
        'glyphicon-hdd' => 'hdd',
        'glyphicon-bullhorn' => 'bullhorn',
        'glyphicon-bell' => 'bell',
        'glyphicon-certificate' => 'certificate',
        'glyphicon-thumbs-up' => 'thumbs up',
        'glyphicon-thumbs-down' => 'thumbs down',
        'glyphicon-hand-right' => 'hand right',
        'glyphicon-hand-left' => 'hand left',
        'glyphicon-hand-up' => 'hand up',
        'glyphicon-hand-down' => 'hand down',
        'glyphicon-circle-arrow-right' => 'circle arrow right',
        'glyphicon-circle-arrow-left' => 'circle arrow left',
        'glyphicon-circle-arrow-up' => 'circle arrow up',
        'glyphicon-circle-arrow-down' => 'circle arrow down',
        'glyphicon-globe' => 'globe',
        'glyphicon-wrench' => 'wrench',
        'glyphicon-tasks' => 'tasks',
        'glyphicon-filter' => 'filter',
        'glyphicon-briefcase' => 'briefcase',
        'glyphicon-fullscreen' => 'fullscreen',
        'glyphicon-dashboard' => 'dashboard',
        'glyphicon-paperclip' => 'paperclip',
        'glyphicon-heart-empty' => 'heart empty',
        'glyphicon-link' => 'link',
        'glyphicon-phone' => 'phone',
        'glyphicon-pushpin' => 'pushpin',
        'glyphicon-usd' => 'usd',
        'glyphicon-gbp' => '',
        'glyphicon-sort' => 'sort',
        'glyphicon-sort-by-alphabet' => 'sort by alphabet',
        'glyphicon-sort-by-alphabet-alt' => 'sort by alphabet-alt',
        'glyphicon-sort-by-order' => 'sort by order',
        'glyphicon-sort-by-order-alt' => 'sort by order-alt',
        'glyphicon-sort-by-attributes' => 'sort by attributes',
        'glyphicon-sort-by-attributes-alt' => 'sort by attributes-alt',
        'glyphicon-unchecked' => 'unchecked',
        'glyphicon-expand' => 'expand',
        'glyphicon-collapse-down' => 'collapse down',
        'glyphicon-collapse-up' => 'collapse up',
        'glyphicon-log-in' => 'log-in',
        'glyphicon-flash' => 'flash',
        'glyphicon-log-out' => 'log-out',
        'glyphicon-new-window' => 'new window',
        'glyphicon-record' => 'record',
        'glyphicon-save' => 'save',
        'glyphicon-open' => 'open',
        'glyphicon-saved' => 'saved',
        'glyphicon-import' => 'import',
        'glyphicon-export' => 'export',
        'glyphicon-send' => 'send',
        'glyphicon-floppy-disk' => 'floppy disk',
        'glyphicon-floppy-saved' => 'floppy saved',
        'glyphicon-floppy-remove' => 'floppy remove',
        'glyphicon-floppy-save' => 'floppy save',
        'glyphicon-floppy-open' => 'floppy open',
        'glyphicon-credit-card' => 'credit card',
        'glyphicon-transfer' => 'transfer',
        'glyphicon-cutlery' => 'cutlery',
        'glyphicon-header' => 'header',
        'glyphicon-compressed' => 'compressed',
        'glyphicon-earphone' => 'earphone',
        'glyphicon-phone-alt' => 'Phone-alt',
        'glyphicon-tower' => 'tower',
        'glyphicon-stats' => 'stats',
        'glyphicon-sd-video' => 'video-SD',
        'glyphicon-hd-video' => 'video-HD',
        'glyphicon-subtitles' => 'subtitles',
        'glyphicon-sound-stereo' => 'stereo',
        'glyphicon-sound-dolby' => 'dolby',
        'glyphicon-sound-5-1' => 'Surround Sound 5.1',
        'glyphicon-sound-6-1' => 'Surround Sound 6.1',
        'glyphicon-sound-7-1' => 'Surround Sound 7.1',
        'glyphicon-copyright-mark' => 'copyright mark',
        'glyphicon-registration-mark' => 'registration mark',
        'glyphicon-cloud-download' => 'cloud download',
        'glyphicon-cloud-upload' => 'cloud upload',
        'glyphicon-tree-conifer' => 'tree conifer',
        'glyphicon-tree-deciduous' => 'tree deciduous',
        'glyphicon-cd' => 'cd',
        'glyphicon-save-file' => 'save file',
        'glyphicon-open-file' => 'open file',
        'glyphicon-level-up' => 'level up',
        'glyphicon-copy' => 'copy',
        'glyphicon-paste' => 'paste',
        'glyphicon-alert' => 'alert',
        'glyphicon-equalizer' => 'equalizer',
        'glyphicon-king' => 'king',
        'glyphicon-queen' => 'queen',
        'glyphicon-pawn' => 'pawn',
        'glyphicon-bishop' => 'bishop',
        'glyphicon-knight' => 'knight',
        'glyphicon-baby-formula' => 'baby formula',
        'glyphicon-tent' => 'tent',
        'glyphicon-blackboard' => 'blackboard',
        'glyphicon-bed' => 'bed',
        'glyphicon-apple' => 'apple',
        'glyphicon-erase' => 'erase',
        'glyphicon-hourglass' => 'hourglass',
        'glyphicon-lamp' => 'lamp',
        'glyphicon-duplicate' => 'duplicate',
        'glyphicon-piggy-bank' => 'piggy bank',
        'glyphicon-scissors' => 'scissors',
        'glyphicon-bitcoin' => 'bitcoin',
        'glyphicon-btc' => 'btc',
        'glyphicon-xbt' => 'xbt',
        'glyphicon-yen' => 'yen',
        'glyphicon-jpy' => 'jpy',
        'glyphicon-ruble' => 'ruble',
        'glyphicon-rub' => 'rub',
        'glyphicon-scale' => 'scale',
        'glyphicon-ice-lolly' => 'ice lolly',
        'glyphicon-ice-lolly-tasted' => 'ice lolly tasted',
        'glyphicon-education' => 'education',
        'glyphicon-option-horizontal' => 'option horizontal',
        'glyphicon-option-vertical' => 'option vertical',
        'glyphicon-menu-hamburger' => 'menu hamburger',
        'glyphicon-modal-window' => 'modal window',
        'glyphicon-oil' => 'oil',
        'glyphicon-grain' => 'grain',
        'glyphicon-sunglasses' => 'sunglasses',
        'glyphicon-text-size' => 'text size',
        'glyphicon-text-color' => 'text color',
        'glyphicon-text-background' => 'text background',
        'glyphicon-object-align-top' => 'object align top',
        'glyphicon-object-align-bottom' => 'object align bottom',
        'glyphicon-object-align-horizontal' => 'object align horizontal',
        'glyphicon-object-align-left' => 'object align left',
        'glyphicon-object-align-vertical' => 'object align vertical',
        'glyphicon-object-align-right' => 'object align right',
        'glyphicon-triangle-right' => 'triangle right',
        'glyphicon-triangle-left' => 'triangle left',
        'glyphicon-triangle-bottom' => 'triangle bottom',
        'glyphicon-triangle-top' => 'triangle top',
        'glyphicon-console' => 'console',
        'glyphicon-superscript' => 'superscript',
        'glyphicon-subscript' => 'subscript',
        'glyphicon-menu-left' => 'menu left',
        'glyphicon-menu-right' => 'menu right',
        'glyphicon-menu-down' => 'menu down',
        'glyphicon-menu-up' => 'menu up',
      );


}

function jit_web_set_all_fields_property(&$fields,$setting,$property,$value){
    foreach($fields as $index => $field){
        $fields[$index]->$setting->$property = $value;
    }
}

function jit_web_get_custom_section_name_by_code($section_code,$nodetype){
    $query = db_select('jit_settings_nodetype_sections','nts')
        ->fields('nts',array('section_code','section_name'))
        ->condition('node_type',$nodetype,'=')
        ->condition('section_code',$section_code,'=')
        ->execute()
        ->fetchAllKeyed(0);

    //if this query returns anything other than 1 solution, return FALSE
    if(count($query) != 1){
        return FALSE;
    }else{
        return $query[$section_code];
    }


}

function jit_web_get_node_type_addtional_settings($settings = NULL){


    return array(
        'additional_settings__active_tab'=>'edit-workflow',
        'comment_anonymous'=>'0',
        'comment_default_mode'=>'1',
        'comment_default_per_page'=>'50',
        'comment'=>'0',
        'comment_form_location'=>'1',
        'comment_preview'=>'1',
        'comment_subject_field'=>'1',
        'menu_options'=> array(),
        'menu_parent'=> 'main-menu:0',
        'node_options'=> array(0,'status'),
        'node_preview'=> '1',
        'node_submitted'=> '0',

    );
}

function jit_web_get_next_field_weight(&$field_weight){
    $weight = $field_weight;
    $field_weight++;
    return $weight;

}

function jit_web_get_measurement_units(){
    return array(
        'MM' => 'Millimeters',
        'CM' => 'Centimeters',
        'M' => 'Meters',
        'IN' => 'Inches',
        'FT' => 'Feet',
        'YD' => 'Yards',
      );
}

function jit_web_get_allowed_colors(){
    return array(
        'BL' => 'Black',
        'WH' => 'White',
        'GR' => 'Gray',
        'R' => 'Red',
        'G' => 'Green',
        'Y' => 'Yellow',
        'B' => 'Blue',
        'O' => 'Orange',
        'P' => 'Purple',
        'PK' => 'Pink',
        'C' => 'Cyan',
        'M' => 'Magenta',
        'V' => 'Violet',
        'BR' => 'Brown',
        'CL' => 'Clear',
        'RT' => 'Red Transparent',
        'MT' => 'Metallized',
      );
}

function jit_web_get_ip_certification_ratings(){
    return array(
        'IP00'=>'IP00',
        'IPX1'=>'IPX1',
        'IPX2'=>'IPX2',
        'IPX3'=>'IPX3',
        'IPX4'=>'IPX4',
        'IPX5'=>'IPX5',
        'IPX6'=>'IPX6',
        'IPX6K'=>'IPX6K',
        'IPX7'=>'IPX7',
        'IPX8'=>'IPX8',
        'IPX9K'=>'IPX9K',
        'IP11'=>'IP11',
        'IP12'=>'IP12',
        'IP13'=>'IP13',
        'IP14'=>'IP14',
        'IP15'=>'IP15',
        'IP16'=>'IP16',
        'IP16K'=>'IP16K',
        'IP17'=>'IP17',
        'IP18'=>'IP18',
        'IP19K'=>'IP19K',
        'IP21'=>'IP21',
        'IP22'=>'IP22',
        'IP23'=>'IP23',
        'IP24'=>'IP24',
        'IP25'=>'IP25',
        'IP26'=>'IP26',
        'IP26K'=>'IP26K',
        'IP27'=>'IP27',
        'IP28'=>'IP28',
        'IP29K'=>'IP29K',
        'IP31'=>'IP31',
        'IP32'=>'IP32',
        'IP33'=>'IP33',
        'IP34'=>'IP34',
        'IP35'=>'IP35',
        'IP36'=>'IP36',
        'IP36K'=>'IP36K',
        'IP37'=>'IP37',
        'IP38'=>'IP38',
        'IP39K'=>'IP39K',
        'IP41'=>'IP41',
        'IP42'=>'IP42',
        'IP43'=>'IP43',
        'IP44'=>'IP44',
        'IP45'=>'IP45',
        'IP46'=>'IP46',
        'IP46K'=>'IP46K',
        'IP47'=>'IP47',
        'IP48'=>'IP48',
        'IP49K'=>'IP49K',
        'IP51'=>'IP51',
        'IP52'=>'IP52',
        'IP53'=>'IP53',
        'IP54'=>'IP54',
        'IP55'=>'IP55',
        'IP56'=>'IP56',
        'IP56K'=>'IP56K',
        'IP57'=>'IP57',
        'IP58'=>'IP58',
        'IP59K'=>'IP59K',
        'IP61'=>'IP61',
        'IP62'=>'IP62',
        'IP63'=>'IP63',
        'IP64'=>'IP64',
        'IP65'=>'IP65',
        'IP66'=>'IP66',
        'IP66K'=>'IP66K',
        'IP67'=>'IP67',
        'IP68'=>'IP68',
        'IP69K'=>'IP69K',
    );
}

function jit_web_get_ip_addtional_certification_ratings(){
    return array(
      'A'=>'Protected Against Access by Back of Hand',
      'B'=>'Protected Against Access by Finger',
      'C'=>'Protected Against Access by Tool',
      'D'=>'Protected Against Access by Wire',
      'f'=>'Oil Resistant',
      'H'=>'High Voltage Device',
      'M'=>'Device Moving During Water Test',
      'S'=>'Device Standing Still During Water Test',
      'W'=>'Weather Conditions',
    );
}

function jit_web_get_nema_certification_ratings(){
    return array(
      '1'=>'1',
      '2'=>'2',
      '3'=>'3',
      '3S'=>'3S',
      '3R'=>'3R',
      '3X'=>'3X',
      '4'=>'4',
      '4x'=>'4x',
      '5'=>'5',
      '6' => '6P',
      '7'=>'7',
      '8'=>'8',
      '9'=>'9',
      '10'=>'10',
      '11'=>'11',
      '12'=>'12',
      '12K'=>'12K',
      '13'=>'13',

    );
}

function jit_web_get_ul94_ratings(){
    return array(
        'HB' => 'HB',
        'V0' => 'V0',
        'V1' => 'V1',
        'V2' => 'V2',
        '5VA' => '5VA',
        '5VB' => '5VB',
        'HF1' => 'HF1',
        'HF2' => 'HF2',
    );
}

function jit_web_get_housing_types(){
    return array(
      'CL' => 'Closed',
      'FX' => 'Fixed',
      'PL' => 'Pluggable',
      'KO' => 'Knockout',
    );
}

function jit_web_get_sizes(){

    return array(
      'S' => 'Small',
      'M' => 'Medium',
      'L' => 'Large',
      'XL' => 'Extra Large',
    );
}

function jit_web_get_number_select($field){
    return;
}
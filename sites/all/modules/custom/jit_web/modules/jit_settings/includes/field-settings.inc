<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Implements hook_field_info_alter();

function jit_settings_field_info_alter(&$info) {
    foreach($info as $index => $field_type){
       if(!isset($info[$index]['settings']['jit_type'])){
        $info[$index]['settings']['jit_type'] = 'na';
       }
    }
}
 *
 */

/**
 * Implements hook_field_settings_form();
 *
 * NOTE: In order for this to work properly for both Products and Product display fields
 *       the product and product displays need to have the SAME MACHINE NAME.  This is
 *       allowed since they are two separate entity types.
 */
function jit_settings_form_field_ui_field_edit_form_alter(&$form, &$form_state, $form_id){

  $fields = array();

  $node_type = $form['instance']['bundle']['#value'];

  //substitute all custom names based on node type's settings
  foreach(jit_web_get_panel_settings() as $section_code => $section ){

      if(stripos($section->section_name, 'custom')!== FALSE){
          //Get custom name from node type settings

          $custom_name = jit_web_get_custom_section_name_by_code($section_code,$node_type);

          //if custom name is not FALSE, insert it as a selection into the $fields
          if($custom_name !== FALSE){
          $fields[$section_code] = $section->panel_name.': '.$custom_name;
          }
      }else{
          $fields[$section_code] = t($section->panel_name.': '.$section->section_name);
      }
  }

  $fields['na']= t('Not Used');

  //

  $form['field']['settings']['jit_type'] = array(
  '#type' => 'radios',
  '#default_value' => jit_web_field_get_jit_type_by_id($form['#field']['id']),
  '#options' => $fields,
  '#title' => t('What Product Section is this field associated with?'),

    );

    $form['#submit'][] = 'jit_settings_save_field_settings';

}


function jit_settings_save_field_settings(&$form, &$form_state){
    $jit_type = $form_state['values']['field']['settings']['jit_type'];
    if($jit_type != 'na'){
        $field = array(
        'fid' => $form['#instance']['field_id'],
        'vid' => $form['#instance']['id'],
        'jit_type' => $jit_type,
        'field_name' => $form['#instance']['label'],
        'field_machine_name' => $form['#instance']['field_name'],
        );
        jit_settings_update_fields($field);
    }


}








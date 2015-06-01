<?php

/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_views_bootstrap_multicarousel_plugin_style(&$vars) {
  drupal_add_js(array(
    'viewsBootstrapMultiCarousel' => array(
      'carousel' => array(
        $vars['id'] => array(
          'id' => $vars['id'],
          'name' => $vars['view']->name,
          'attributes' => array(
            'interval' => $vars['options']['interval'] ? (int)$vars['options']['interval'] : FALSE,
            'pause' => $vars['options']['pause'] ? 'hover' : FALSE,
          ),
        ),
      ),
    ),
  ), 'setting');

  drupal_add_js(drupal_get_path('module', 'views_bootstrap_multicarousel') . '/js/views-bootstrap-multicarousel.js');
  //drupal_add_js(drupal_get_path('module', 'views_bootstrap_multicarousel') . '/js/views-bootstrap-multicarousel-responsive.js');

  drupal_add_css(drupal_get_path('module', 'views_bootstrap_multicarousel') . '/css/views-bootstrap-multicarousel.css', array('group' => CSS_THEME, 'every_page' => FALSE));

  $vars['classes_array'][] = 'carousel slide';

  $vars['navigation'] = (bool)$vars['options']['navigation'];
  $vars['indicators'] = (bool)$vars['options']['indicators'];

  views_bootstrap_multicarousel_views_bootstrap_multicarousel_format_rows($vars);

}
/*
 * this function handles the creation of the multicarousel slides by duplicating
 * all the result rows in the proper order in each row
 */
function views_bootstrap_multicarousel_views_bootstrap_multicarousel_format_rows(&$vars){
  //first we copy the original rows into their own array for safe keeping
  $vars['multicarousel_items'] = $vars['rows'];

  //now unset the row array so we can manipulate it.
  unset($vars['rows']);


  $row_count = count($vars['multicarousel_items']);

  //initiate our starter and ender rows
  $vars['starter_row'] = getBufferRow($row_count, 'front');
  $vars['ender_row'] = getBufferRow($row_count, 'back');



  for ($i = 0; $i < $row_count; $i++) {
      $j = $i-1;
      $vars['rows'][$i] = '';
      for ($k = 0; $k < $row_count; $k++) {
          if($j < 0){
              $j = ($row_count -1);
          }
          $test = str_replace('%views-bootstrap-multicarousel-replacement%',getSlideClasses($k,$row_count),$vars['multicarousel_items'][$j]);
          $vars['rows'][$i] .= $test;

          $j--;

      }
  }



}


/**
 * Implementation of template preprocess for the view fields.
 */
function template_preprocess_views_bootstrap_multicarousel_plugin_rows(&$vars) {
  $view = &$vars['view'];

  $vars['row_classes'] = '%views-bootstrap-multicarousel-replacement%';

  foreach ($vars['options'] as $id => $field) {
    if (isset($view->field[$field])) {
      $vars[$id] = $view->style_plugin->get_field($view->row_index, $field);
    }
  }
}

/*
 * This function creates the classes for the main rows based on the row
 * position passed to the function and the total row count.
 */
function getSlideClasses($row_position, $row_count){
    $classes = '';
    $xs_size = 0;
    $sm_size = 0;
    $md_size = 0;
    $lg_size = 0;
    $ending_class = 'text-center';

    switch ($row_count) {
        case 0:
            $xs_size = 0;
            $sm_size = 0;
            $md_size = 0;
            $lg_size = 0;
            getClassesByTotalCount($classes, $row_position, $row_count, $xs_size, $sm_size, $md_size, $lg_size);
            break;
        case 1:
            $xs_size = 8;
            $sm_size = 4;
            $md_size = 4;
            $lg_size = 4;
            getClassesByTotalCount($classes, $row_position, $row_count, $xs_size, $sm_size, $md_size, $lg_size);
            break;
        case 2:
            $xs_size = 8;
            $sm_size = 3;
            $md_size = 3;
            $lg_size = 3;
            getClassesByTotalCount($classes, $row_position, $row_count, $xs_size, $sm_size, $md_size, $lg_size);
            break;
        default:
            $xs_size = 8;
            $sm_size = 4;
            $md_size = 2;
            $lg_size = 2;
            getClassesByTotalCount($classes, $row_position, $row_count, $xs_size, $sm_size, $md_size, $lg_size);
            break;

    }


    if (strlen($classes) != 0){
        $classes .=' ';
    }

    $classes .= $ending_class;
    return $classes;
}



/*
 * this function returns the side buffers to the carousel to ensure items
 * are spaced properly.
 */

function getBufferRow($row_count, $position){
    //'<div class="col-xs-2 visible-xs-block views-bootstrap-multicarousel-front"></div>'
    $classes = '';
    $xs_size = 0;
    $sm_size = 0;
    $md_size = 0;
    $lg_size = 0;
    $ending_class = 'views-bootstrap-multicarousel-'.$position;

    switch ($row_count) {
        case 0:
            $xs_size = 0;
            $sm_size = 0;
            $md_size = 0;
            $lg_size = 0;
            break;
        case 1:
            $xs_size = 2;
            $sm_size = 4;
            $md_size = 4;
            $lg_size = 4;
            break;
        case 2:
            $xs_size = 2;
            $sm_size = 3;
            $md_size = 3;
            $lg_size = 3;
            break;
        case 3:
            $xs_size = 2;
            $sm_size = 0;
            $md_size = 3;
            $lg_size = 3;
            break;
        case 4:
            $xs_size = 2;
            $sm_size = 0;
            $md_size = 2;
            $lg_size = 2;
            break;
        case 5:
            $xs_size = 2;
            $sm_size = 0;
            $md_size = 2;
            $lg_size = 2;
            break;
        default:
            $xs_size = 2;
            $sm_size = 0;
            $md_size = 0;
            $lg_size = 0;
            break;

    }

    if($xs_size != 0){
        addSize($classes,'xs',$xs_size);
        addVisable($classes,'xs');
    }else{
    addHidden($classes, 'xs');
    }

    if($sm_size != 0){
        addSize($classes,'sm',$xs_size);
        addVisable($classes,'sm');
    }else{
    addHidden($classes, 'sm');
    }

    if($md_size != 0){
        addSize($classes,'md',$xs_size);
        addVisable($classes,'md');
    }else{
    addHidden($classes, 'md');
    }

    if($lg_size != 0){
        addSize($classes,'lg',$xs_size);
        addVisable($classes,'lg');
    }else{
    addHidden($classes, 'lg');
    }

    if (strlen($classes) != 0){
        $classes .=' ';
    }

    $classes .= $ending_class;

        return '<div class = "'.$classes.'"></div>';
}

function addSize(&$classes, $col_class, $col_size){
    if (strlen($classes) != 0){
        $classes .=' ';
    }

    $classes .= 'col-'.$col_class.'-'.$col_size;
}

function addHidden(&$classes, $col_class){

    if (strlen($classes) != 0){
        $classes .=' ';
    }

    $classes .= 'hidden-'.$col_class;
}

function addVisable(&$classes, $col_class, $display = 'block'){
    if (strlen($classes) != 0){
        $classes .=' ';
    }

    $classes .= 'visible-'.$col_class.'-'.$display;
}

function getClassesByTotalCount(&$classes, $row_position, $row_count, $xs_size, $sm_size, $md_size, $lg_size){

    if ($row_count > 5){
        switch ($row_position) {
        case 0:
            ($xs_size !=0) ? addSize($classes,'xs',$xs_size):addHidden($classes,'xs');
            ($sm_size !=0) ? addSize($classes,'sm',$sm_size):addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;

        case 1:
            addHidden($classes,'xs');
            ($sm_size !=0) ? addSize($classes,'sm',$sm_size):addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;

        case 2:
            addHidden($classes,'xs');
            ($sm_size !=0) ? addSize($classes,'sm',$sm_size):addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;

        default:
            addHidden($classes,'xs');
            addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;

        }
    }else if ($row_count > 3){
        switch ($row_position) {
        case 0:
            ($xs_size !=0) ? addSize($classes,'xs',$xs_size):addHidden($classes,'xs');
            ($sm_size !=0) ? addSize($classes,'sm',$sm_size):addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;

        case 1:
            addHidden($classes,'xs');
            ($sm_size !=0) ? addSize($classes,'sm',$sm_size):addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;

        case 2:
            addHidden($classes,'xs');
            ($sm_size !=0) ? addSize($classes,'sm',$sm_size):addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;

        case 3:
            addHidden($classes,'xs');
            addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;
        default:
            addHidden($classes,'xs');
            addHidden($classes,'sm');
            addHidden($classes,'md');
            addHidden($classes,'lg');
            break;

        }
    }else if ($row_count > 1){
        switch ($row_position) {
        case 0:
            ($xs_size !=0) ? addSize($classes,'xs',$xs_size):addHidden($classes,'xs');
            ($sm_size !=0) ? addSize($classes,'sm',$sm_size):addHidden($classes,'sm');
            ($md_size !=0) ? addSize($classes,'md',$md_size):addHidden($classes,'md');
            ($lg_size !=0) ? addSize($classes,'lg',$lg_size):addHidden($classes,'lg');
            break;

        default:
            addHidden($classes,'xs');
            addHidden($classes,'sm');
            addHidden($classes,'md');
            addHidden($classes,'lg');
            break;

        }
    }
}
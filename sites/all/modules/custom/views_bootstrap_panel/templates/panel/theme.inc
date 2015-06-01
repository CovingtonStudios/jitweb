<?php

/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_views_bootstrap_panel_plugin_style(&$vars) {
  $view = &$vars['view'];
  $title_field = $vars['options']['title_field'];
  $body_field = $vars['options']['body_field'];

  $vars['classes_array'][] = 'panel-group';

  // Get titles.
  if (isset($view->field[$title_field])) {
    foreach ($vars['view']->result as $key => $field) {
      $vars['titles'][$key] = strip_tags($view->style_plugin->get_field($key, $title_field));
      if(isset($view->field[$body_field])){
        $vars['bodies'][$key] = $view->style_plugin->get_field($key, $body_field);
      }

    }
  }
}

<?php
/**
 * @file
 * Provide views data and handlers.
 */

/**
 * Implements hook_views_plugins().
 */
function views_bootstrap_panel_views_plugins() {
  $module_path = drupal_get_path('module', 'views_bootstrap_panel');

  return array(
    'style' => array(
      'views_bootstrap_panel_plugin_style' => array(
        'title' => t('Bootstrap Panel'),
        'help' => t('Bootstrap Panel Style'),
        'path' => $module_path . '/plugins/panel',
        'handler' => 'ViewsBootstrapPanelPluginStyle',
        'parent' => 'default',
        'theme' => 'views_bootstrap_panel_plugin_style',
        'theme path' => $module_path . '/templates/panel',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses grouping' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),

    ),

  );
}

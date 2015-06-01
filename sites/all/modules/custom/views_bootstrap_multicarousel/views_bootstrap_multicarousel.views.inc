<?php
/**
 * @file
 * Provide views data and handlers.
 */

/**
 * Implements hook_views_plugins().
 */
function views_bootstrap_multicarousel_views_plugins() {
  $module_path = drupal_get_path('module', 'views_bootstrap_multicarousel');

  return array(
    'style' => array(
      'views_bootstrap_multicarousel_plugin_style' => array(
        'title' => t('Bootstrap MultiCarousel'),
        'help' => t('Bootstrap MultiCarousel Style'),
        'path' => $module_path . '/plugins/multicarousel',
        'handler' => 'ViewsBootstrapMultiCarouselPluginStyle',
        'parent' => 'default',
        'theme' => 'views_bootstrap_multicarousel_plugin_style',
        'theme path' => $module_path . '/templates/multicarousel',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses grouping' => FALSE,
        'uses options' => TRUE,
        'type' => 'normal',
      )
    ),
    'row' => array(
      'views_bootstrap_multicarousel_plugin_rows' => array(
        'title' => t('Bootstrap MultiCarousel'),
        'help' => t('Choose the fields to display in Bootstrap MultiCarousel Style.'),
        'path' => $module_path . '/plugins/multicarousel',
        'handler' => 'ViewsBootstrapMultiCarouselPluginRows',
        'theme' => 'views_bootstrap_multicarousel_plugin_rows',
        'theme path' => $module_path . '/templates/multicarousel',
        'theme file' => 'theme.inc',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      )
    ),
  );
}

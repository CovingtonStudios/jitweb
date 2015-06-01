<?php
module_load_include('inc', 'jit_web', 'includes/fields');
module_load_include('inc', 'jit_web', 'includes/instances');
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Implements hook_node_info().
 */
function jit_web_node_info() {
  $items = array(
    'datasheets' => array(
      'name' => t('Datasheets'),
      'base' => 'jit_web',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'drawings' => array(
      'name' => t('Drawings'),
      'base' => 'jit_web',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'front_page_carousel_items' => array(
      'name' => t('Front Page Carousel Items'),
      'base' => 'jit_web',
      'description' => t('If you would like to add an item to the Front Page Carousel, use this content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'material' => array(
      'name' => t('Material'),
      'base' => 'jit_web',
      'description' => t('Materials that our parts are made out of'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'organization_links' => array(
      'name' => t('Organization Links'),
      'base' => 'jit_web',
      'description' => t('Use this content type to add any JIT Organization Links found under the reference Menu'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'partnership_links' => array(
      'name' => t('Partnership Links'),
      'base' => 'jit_web',
      'description' => t('These are the records for JIT manufacturer partners'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'references' => array(
      'name' => t('References'),
      'base' => 'jit_web',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
      
    ),
    'splash_section' => array(
      'name' => t('Splash Section'),
      'base' => 'jit_web',
      'description' => t('This content type will be used to add splash sections to the front page. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'standards' => array(
      'name' => t('Standards'),
      'base' => 'jit_web',
      'description' => t('These are Standards consistent with JIT\'s enclosures'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'value_added_service' => array(
      'name' => t('Value Added Service'),
      'base' => 'jit_web',
      'description' => t('This content type is for any Value Added Services that JIT Offer.  '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

function jit_web_node_type_insert($content_type) {
  if ($content_type->base == 'jit_web') {
    // First we add the body field. Node API helpfully gives us
    // node_add_body_field().
    // We'll set the body label now, although we could also set
    // it along with our other instance properties later.

    jit_web_update_nodetype_variables($content_type);


    $body_instance = node_add_body_field($content_type, t('Example Description'));

    // Add our example_node_list view mode to the body instance
    // display by instructing the body to display as a summary.
    $body_instance['display']['example_node_list'] = array(
      'label' => 'hidden',
      'type' => 'text_summary_or_trimmed',
    );

    // Save our changes to the body field instance.
    field_update_instance($body_instance);

    // Create all the fields we are adding to our content type.
    foreach (jit_web_field_default_field_bases() as $field) {
        if(!jit_web_field_exists($field['field_name'])){
            field_create_field($field);
        }
    }

    // Create all the instances for our fields.
    foreach (jit_web_field_default_field_instances() as $instance) {
        if(!jit_web_instance_exists($instance,'node')){
          field_create_instance($instance);
        }
    }
  }
}
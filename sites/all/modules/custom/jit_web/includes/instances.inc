<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Implements hook_field_default_field_instances().
 */
function jit_web_field_default_field_instances() {
  $field_instances = array();


  // Exported field_instance: 'node-datasheets-field_datasheet'
  $field_instances['node-datasheets-field_datasheet'] = array(
    'bundle' => 'datasheets',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_datasheet',
    'label' => 'Datasheet',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '[current-page:title]/datasheet',
      'file_extensions' => 'txt pdf doc xls',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_partnership_logo' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 33,
    ),
  );


  // Exported field_instance: 'node-drawings-field_drawing'
  $field_instances['node-drawings-field_drawing'] = array(
    'bundle' => 'drawings',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_drawing',
    'label' => 'Drawing',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '[current-page:title]/drawings',
      'file_extensions' => 'txt pdf doc xls',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_partnership_logo' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'node-front_page_carousel_items-field_carousel_image'
  $field_instances['node-front_page_carousel_items-field_carousel_image'] = array(
    'bundle' => 'front_page_carousel_items',
    'deleted' => 0,
    'description' => 'This picture should be at LEAST 900x500 to prevent distortion on the main page',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_carousel_image',
    'label' => 'Carousel Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'Carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '800x450',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_jit_product_fullbreakpoints_theme_jit_mobile_1x' => 0,
          'image_jit_product_fullbreakpoints_theme_jit_narrow_1x' => 0,
          'image_jit_product_fullbreakpoints_theme_jit_normal_1x' => 0,
          'image_jit_product_fullbreakpoints_theme_jit_wide_1x' => 0,
          'image_jit_product_thumb' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_partnership_logo' => 0,
          'image_product_thumbbreakpoints_theme_jit_mobile_1x' => 0,
          'image_product_thumbbreakpoints_theme_jit_narrow_1x' => 0,
          'image_product_thumbbreakpoints_theme_jit_normal_1x' => 0,
          'image_product_thumbbreakpoints_theme_jit_wide_1x' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 32,
    ),
  );



  // Exported field_instance: 'node-material-field_datasheet'
  $field_instances['node-material-field_datasheet'] = array(
    'bundle' => 'material',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_datasheet',
    'label' => 'Datasheet',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '[current-page:title]/datasheet',
      'file_extensions' => 'txt pdf doc xls',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_jit_product_fullbreakpoints_theme_jit_mobile_1x' => 0,
          'image_jit_product_fullbreakpoints_theme_jit_narrow_1x' => 0,
          'image_jit_product_fullbreakpoints_theme_jit_normal_1x' => 0,
          'image_jit_product_fullbreakpoints_theme_jit_wide_1x' => 0,
          'image_jit_product_thumb' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_partnership_logo' => 0,
          'image_product_thumbbreakpoints_theme_jit_mobile_1x' => 0,
          'image_product_thumbbreakpoints_theme_jit_narrow_1x' => 0,
          'image_product_thumbbreakpoints_theme_jit_normal_1x' => 0,
          'image_product_thumbbreakpoints_theme_jit_wide_1x' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-organization_links-field_url'
  $field_instances['node-organization_links-field_url'] = array(
    'bundle' => 'organization_links',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the Website Address (URL) of the Organization being added.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_url',
    'label' => 'URL',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 32,
    ),
  );



  // Exported field_instance: 'node-partnership_links-field_company_logo'
  $field_instances['node-partnership_links-field_company_logo'] = array(
    'bundle' => 'partnership_links',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_company_logo',
    'label' => 'Company Logo',
    'required' => 1,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'Partnership_Link_Logos',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 1,
        'insert_absolute' => 1,
        'insert_class' => 'img-responsive',
        'insert_default' => 'image',
        'insert_styles' => array(
          '<all>' => '<all>',
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-partnership_links-field_url'
  $field_instances['node-partnership_links-field_url'] = array(
    'bundle' => 'partnership_links',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the Web address (URL) for the manufacturer partnership link.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 'optional',
      'user_register_form' => FALSE,
      'validate_url' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-references-field_reference_view'
  $field_instances['node-references-field_reference_view'] = array(
    'bundle' => 'references',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reference_view',
    'label' => 'Reference View',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'commerce_cart_block' => 0,
        'commerce_cart_form' => 0,
        'commerce_cart_summary' => 0,
        'commerce_customer_profiles' => 0,
        'commerce_line_item_table' => 0,
        'commerce_order_revisions' => 0,
        'commerce_orders' => 0,
        'commerce_payment_order' => 0,
        'commerce_product_revisions' => 0,
        'commerce_products' => 0,
        'commerce_user_orders' => 0,
        'entityform_type_list' => 0,
        'entityforms' => 0,
        'organization_links' => 'organization_links',
        'partnership_links' => 'partnership_links',
        'products' => 0,
        'references' => 'references',
        'related_products' => 0,
        'standards' => 'standards',
        'taxonomy_term' => 0,
        'user_entityforms' => 0,
        'value_added_services' => 0,
        'view_accessories' => 0,
      ),
      'force_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 31,
    ),
  );



  // Exported field_instance: 'node-splash_section-field_base_icon'
  $field_instances['node-splash_section-field_base_icon'] = array(
    'bundle' => 'splash_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_base_icon',
    'label' => 'Base Icon',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-splash_section-field_base_icon_color_class'
  $field_instances['node-splash_section-field_base_icon_color_class'] = array(
    'bundle' => 'splash_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_base_icon_color_class',
    'label' => 'Base Icon Color Class',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-splash_section-field_base_icon_size_class'
  $field_instances['node-splash_section-field_base_icon_size_class'] = array(
    'bundle' => 'splash_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_base_icon_size_class',
    'label' => 'Base Icon Size Class',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-splash_section-field_stacked_icon'
  $field_instances['node-splash_section-field_stacked_icon'] = array(
    'bundle' => 'splash_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stacked_icon',
    'label' => 'Stacked Icon',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-splash_section-field_stacked_icon_color_class'
  $field_instances['node-splash_section-field_stacked_icon_color_class'] = array(
    'bundle' => 'splash_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stacked_icon_color_class',
    'label' => 'Stacked Icon Color Class',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'node-splash_section-field_stacked_icon_size_class'
  $field_instances['node-splash_section-field_stacked_icon_size_class'] = array(
    'bundle' => 'splash_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stacked_icon_size_class',
    'label' => 'Stacked Icon Size Class',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-splash_section-field_weight'
  $field_instances['node-splash_section-field_weight'] = array(
    'bundle' => 'splash_section',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter Weight of section on the page.  Higher weight sections move to the right.  NOTE: In the case of an ODD number of number of published sections, weight 0 will always be shown in the middle of the set and will break out to it\'s own row in the small viewport.  For an even number of sections, it will be at position 0 all the way at the left and will NOT breakout to it\'s own row on the small viewport.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_weight',
    'label' => 'Weight',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-standards-field_standards_files'
  $field_instances['node-standards-field_datasheet'] = array(
    'bundle' => 'standards',
    'deleted' => 0,
    'description' => 'This is the PDF file that goes along with the Standard being added',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_table',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_datasheet',
    'label' => 'Standards Files',
    'required' => 1,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'References/Standard_Files',
      'file_extensions' => 'txt doc docx pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 31,
    ),
  );



  // Exported field_instance: 'node-value_added_service-field_image'
  $field_instances['node-value_added_service-field_image'] = array(
    'bundle' => 'value_added_service',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Value Added Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'Value Added Images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 1,
        'insert_absolute' => 1,
        'insert_class' => 'img-responsive',
        'insert_default' => 'image',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 'image',
          'image_large' => 'image_large',
          'image_medium' => 'image_medium',
          'image_thumbnail' => 'image_thumbnail',
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 33,
    ),
  );

  return $field_instances;
}

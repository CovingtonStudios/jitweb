<?php

/*
 * This is the template for all product type and product displays that will be added
 * automatically when this module is installed.  when you create a new "Product"
 * you need to create the file with the machine name as the file name, and the
 * extension of .product
 *
 * example: din_rail.product
 *
 * Then you need fill in the $type (machine name) and $name (human readable name)
 * as well as all of the custom fields that are associated with this product type
 * and product display by following the examples below.
 *
 */

  $ptype = '';
  $pname = '';
  $pmodule = 'jit_products';
  $field_weight = 0;

/*
 * create product
 */

  $product_type = commerce_product_ui_product_type_new();

  $product_type['type'] = $ptype;
  $product_type['name'] = $pname;
  $product_type['description'] = 'Product Type for '.$pname.'s';
  $product_type['is_new'] = TRUE;
  $product_type['jit_products'] = TRUE;



/*
 * create product Display
 */

    $node_type = new JITNodeType($ptype);

    $node_type->name = $pname;
    $node_type->description = 'This is the product display type for '.$pname.'s';
    $node_type->has_title = '1';
    $node_type->title_label = t('Name');
    $node_type->help = '';
    //setup custom section columns
    //example: $node_type->set_section('cu','Custom Name');


/*
 * create display fields
 */
   $dfields = array();

   /*
    * add the product image
    */

    $name = 'field_product_image';
    $schema_type = 'image';
    $widget_type = 'image_image';
    $dfields[$name] = new JITField($name,$type,$widget_type);
    $dfields[$name]->instance->file_extensions = 'png gif jpg jpeg';
    $dfields[$name]->instance->add_filefield_path('[node:title]/pictures');
    $dfields[$name]->instance->label = 'Product Image';
    $dfields[$name]->instance->widget->add_insert_style('auto');
    $dfields[$name]->instance->add_display_array('default', 'image', $field_weight++, 'above', 'image', array('image_link'=>'','image_style'=>''));

    /*
     * add the product reference
     */
    $name = 'field_product_reference';
    $schema_type = 'commerce_product_reference';
    $widget_type = 'options_buttons';
    $dfields[$name] = new JITField($name,$type,$widget_type);
    $dfields[$name]->schema->cardinality = FIELD_CARDINALITY_UNLIMITED;
    //$dfields['field_product_reference']->instance->bundle = $type;
    $dfields[$name]->instance->label = $name.' Product';
    $dfields[$name]->instance->add_referenceable_type($type);
    $dfields[$name]->instance->add_display_array('default','commerce_cart_add_to_cart_form' , $field_weight++, 'hidden','commerce_cart',array('combine' => TRUE, 'default_quantity' => 1, 'line_item_type' => 'product', 'show_quantity' => FALSE, 'show_single_product_attributes'=>FALSE));

    /*
     * create Datasheet Field
     */

         $name = 'field_product_datasheet';
         $schema_type = 'entityreference';
         $widget_type = 'entityreference_autocomplete';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->add_target_bundle('datasheets');
         $dfields[$name]->schema->target_type = 'node';
         $dfields[$name]->instance->label ='Product Datasheet';
         $dfields[$name]->instance->add_display_array('default','entityreference_entity_view' , $field_weight++, 'hidden','entityreference',array('links'=>1, 'view_mode' => 'default'));


    /*
     * create Details Panel Fields
     */
        /*
         * create Technical Specification Fields
         */
         $name = 'field_manufacturer';
         $schema_type = 'entityreference';
         $widget_type = 'options_select';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'ts';
         $dfields[$name]->schema->add_target_bundle('partnership_links');
         $dfields[$name]->schema->target_type = 'node';
         $dfields[$name]->instance->label ='Manufacturer';
         $dfields[$name]->instance->add_display_array('default','entityreference_label' , $field_weight++, 'above','entityreference',array('links'=>FALSE));



        /*
         * create Color Fields
         * The main part color will be created on the product as color will be a product option
         * fields created here should be for secondary colors (like base color on a DR350)
         */


        /*
         * create Custom Fields
         */




    /*
     * create Dimension Panel Fields
     */
        /*
         * create Part Dimension Fields
         */

         $name = 'field_part_width';
         $schema_type = 'number_decimal';
         $widget_type = 'number';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'dp';
         $dfields[$name]->instance->label ='Part Width';
         $dfields[$name]->instance->add_display_array('default','number_decimal' , $field_weight++, 'above','number',array('decimal_separator'=>'.','prefix_suffix' => TRUE, 'scale'=>2,'thousand_separator'=>' '));



         $name = 'field_part_length';
         $schema_type = 'number_decimal';
         $widget_type = 'number';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'dp';
         $dfields[$name]->instance->label ='Part Length';
         $dfields[$name]->instance->add_display_array('default','number_decimal' , $field_weight++, 'above','number',array('decimal_separator'=>'.','prefix_suffix' => TRUE, 'scale'=>2,'thousand_separator'=>' '));



         $name = 'field_part_height';
         $schema_type = 'number_decimal';
         $widget_type = 'number';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'dp';
         $dfields[$name]->instance->label ='Part Height';
         $dfields[$name]->instance->add_display_array('default','number_decimal' , $field_weight++, 'above','number',array('decimal_separator'=>'.','prefix_suffix' => TRUE, 'scale'=>2,'thousand_separator'=>' '));




        /*
         * create Custom Dimension Fields
         */


    /*
     * create Material Panel Fields
     */

         $name = 'field_part_material';
         $schema_type = 'entityreference';
         $widget_type = 'entityreference_autocomplete';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'm1';
         $dfields[$name]->schema->add_target_bundle('material');
         $dfields[$name]->schema->target_type = 'node';
         $dfields[$name]->instance->label ='Part Material';
         $dfields[$name]->instance->add_display_array('default','entityreference_entity_view' , $field_weight++, 'above','entityreference',array('links'=>1, 'view_mode' => 'default'));


        /*
         * Create Custom Material Fields
         */

    /*
     * create Drawings Panel Fields
     */

         $name = 'field_part_drawing';
         $schema_type = 'entityreference';
         $widget_type = 'entityreference_autocomplete';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'd1';
         $dfields[$name]->schema->add_target_bundle('drawing');
         $dfields[$name]->schema->target_type = 'node';
         $dfields[$name]->instance->label ='Part Drawing';
         $dfields[$name]->instance->add_display_array('default','entityreference_entity_view' , $field_weight++, 'above','entityreference',array('links'=>1, 'view_mode' => 'default'));

        /*
         * create Custom Drawing Fields
         */

    /*
     * create Administrative Panel Fields
     */
        /*
         * create Manufacturer Links Fields
         */
         $name = 'field_manufacturer_site_url';
         $schema_type = 'link_field';
         $widget_type = 'link_field';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'am';
         $dfields[$name]->instance->label ='Manufacturer\'s website Part URL';
         $dfields[$name]->instance->add_display_array('default','link_default' , $field_weight++, 'above','link');


        /*
         * create OSAS Fields
         * Sku would be here, but is automatically created so no need
         */
         $name = 'field_osas_description';
         $schema_type = 'text';
         $widget_type = 'text_textfield';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'ao';
         $dfields[$name]->instance->label = 'OSAS Description';
         $dfields[$name]->instance->add_display_array('default','text_default' , $field_weight++, 'above','text');

        /*
         * create JIT Info Fields
         */
         $name = 'field_jit_info_url';
         $schema_type = 'link_field';
         $widget_type = 'link_field';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->jittype = 'aj';
         $dfields[$name]->instance->label ='JIT Info URL';
         $dfields[$name]->instance->add_display_array('default','link_default' , $field_weight++, 'above','link');


    /*
     * hidden fields
     */

         $name = 'field_measurement_unit';
         $schema_type = 'list_text';
         $widget_type = 'options_select';
         $dfields[$name] = new JITField($name, $schema_type, $widget_type);
         $dfields[$name]->schema->allowed_values_function = 'jit_products_get_measurement_units';
         $dfields[$name]->instance->label ='Unit of Measurement';
         $dfields[$name]->instance->add_display_array('default','hidden' , $field_weight++, 'hidden');

    jit_products_set_all_fields_property($dfields,'instance','bundle',$ptype);

    $node_type->fields = $dfields;


  /*
   * create product fields
   */

    $pfields = array();
    //reset the fields weight
    $field_weight = 0;

    /*
     * create price field
     */
    $name = 'commerce_price';
    $schema_type = 'commerce_price';
    $widget_type = 'commerce_price_full';
    $pfields[$name] = new JITField($name,$type,$widget_type);
    //$pfields['commerce_price']->instance->entity_type = 'commerce_product';
    //$pfields['commerce_price']->instance->bundle = $type;
    $pfields[$name]->instance->label = 'Price';
    $pfields[$name]->instance->required = TRUE;
    $pfields[$name]->instance->add_display_array('default','commerce_price_formatted_amount' , $field_weight++, 'hidden','commerce_price',array('calculation'=>'calculated_sell_price'));

    /*
     * create product options
     * @example
     *
     *
     *    $name = 'field_hole_style';
     *    $type = 'list_text';
     *    $widget_type = 'options_select';
     *    $pfields[$name] = new JITField($name,$type,$widget_type);
     *    $pfields[$name]->schema->jittype = 'cu';
     *    $pfields[$name]->schema->allowed_values = array('na'=>'No Holes', 'bo' => 'Borings', 'cb' => 'Counterbores', 'ib' => 'Integrated Bolts');
     *    $pfields[$name]->instance->label = 'Clip Hole Style';
     *    $pfields[$name]->instance->commerce_attribute_field = 1;
     *    $pfields[$name]->instance->commerce_attribute_widget = 'select';
     *    $pfields[$name]->instance->commerce_attribute_title = 'Hole Style';
     *    $pfields[$name]->instance->add_display_array('default','list_default' , $field_weight++, 'above', 'list');
     *    $pfields[$name]->instance->required = TRUE;
     *
     *
     */






    jit_products_set_all_fields_property($pfields,'instance','bundle',$ptype);

    jit_products_set_all_fields_property($pfields,'instance','entity_type','commerce_product');


    $product_type['fields'] = $pfields;
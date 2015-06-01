<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function jit_settings_get_section_insert_form($form, &$form_state){
    global $user;

    $form['section_name'] = array(

      '#type' => 'textfield',

      '#title' => t('Section Name'),

      '#default_value' => '',

      '#size' => 60,

      '#maxlength' => 128,

      '#required' => TRUE,

    );

    $form['section_code'] = array(

      '#type' => 'textfield',

      '#title' => t('Section Code'),

      '#default_value' => '',

      '#size' => 5,

      '#maxlength' => 2,

      '#required' => TRUE,

    );

    $panels = db_select('jit_settings_panels','p')
        ->fields('p',array('panel_name','panel_name'))
        ->execute()
        ->fetchAllKeyed(0, 1);

    $form['panel_name'] = array(

      '#type' => 'select',

      '#title' => t('Panel Name'),

      '#options' => $panels,

      '#required' => TRUE,

    );

    $form['weight'] = array(

      '#type' => 'textfield',

      '#title' => t('Weight'),

      '#default_value' => 0,

      '#element_validate' => array('jit_settings_validate_numeric_textfield'),

      '#required' => TRUE,

    );

    //TODO: split section and panel up so that I can grab teh custom names without parsing.

    $form['modifiedby'] = array(

      '#type' => 'textfield',

      '#title' => t('Modified By'),

      '#default_value' => $user->name,

      '#size' => 60,

      '#maxlength' => 32,

      '#required' => TRUE,

      '#access' => FALSE,

    );

    $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));

    return $form;
}

function jit_settings_get_section_insert_form_submit($form, &$form_state){
    global $user;

    $section_name = $form_state['values']['section_name'];
    $section_code = $form_state['values']['section_code'];
    $panel_name = $form_state['values']['panel_name'];
    $weight = $form_state['values']['weight'];

    $jid = db_insert('jit_settings_sections')
            ->fields(array(
              'section_name' => $section_name,
              'section_code' => $section_code,
              'panel_name' => $panel_name,
              'weight' => $weight,
              'modifiedby' => $user->name,
            ))
            ->execute();

    $form_state['redirect'] = 'admin/settings/jit_settings';
}

function jit_settings_get_section_edit_form($form, &$form_state,$jid){
    global $user;

    $query = db_select('jit_settings_sections','s')
            ->fields('s', array('section_name','section_code','panel_name','weight'))
            ->condition('jid', $jid, '=')
            ->execute()
            ->fetchAssoc();


    $form['jid'] = array(
      '#type' => 'value',
      '#value' => $jid,
      );

    $form['section_name'] = array(

      '#type' => 'textfield',

      '#title' => t('Section Name'),

      '#default_value' => $query['section_name'],

      '#size' => 60,

      '#maxlength' => 128,

      '#required' => TRUE,

    );

    $form['section_code'] = array(

      '#type' => 'textfield',

      '#title' => t('Section Code'),

      '#default_value' => $query['section_code'],

      '#size' => 5,

      '#maxlength' => 2,

      '#required' => TRUE,

    );

        $panels = db_select('jit_settings_panels','p')
        ->fields('p',array('panel_name','panel_name'))
        ->execute()
        ->fetchAllKeyed(0, 1);

    $form['panel_name'] = array(

      '#type' => 'select',

      '#title' => t('Panel Name'),

      '#default_value' => $query['panel_name'],

      '#options' => $panels,

      '#required' => TRUE,

    );

    $form['weight'] = array(

      '#type' => 'textfield',

      '#title' => t('Weight'),

      '#default_value' => $query['weight'],

      '#element_validate' => array('jit_settings_validate_numeric_textfield'),

      '#required' => TRUE,

    );

    $form['modifiedby'] = array(

      '#type' => 'textfield',

      '#title' => t('Modified By'),

      '#default_value' => $user->name,

      '#size' => 60,

      '#maxlength' => 32,

      '#required' => TRUE,

      '#access' => FALSE,

    );

    $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));

    return $form;
}

function jit_settings_get_section_edit_form_submit($form, &$form_state){
    global $user;

    $section_name = $form_state['values']['section_name'];
    $section_code = $form_state['values']['section_code'];
    $panel_name = $form_state['values']['panel_name'];
    $weight = $form_state['values']['weight'];

    $jid = $form_state['values']['jid'];

    $jid = db_update('jit_settings_sections')
            ->fields(array(
              'section_name' => $section_name,
              'section_code' => $section_code,
              'panel_name' => $panel_name,
              'weight' => $weight,
              'modifiedby' => $user->name,
            ))
            ->condition('jid', $jid, '=')
            ->execute();

    $form_state['redirect'] = 'admin/settings/jit_settings';
}





function jit_settings_delete_section_form($form, &$form_state,$jid){

        $path = 'admin/settings/jit_settings';

        $query = db_select('jit_settings_sections','s')
            ->fields('s', array('section_name','section_code'))
            ->condition('jid', $jid, '=')
            ->execute()
            ->fetchAssoc();

        $form = array();
	$form['jid'] = array(
		'#type' => 'value',
		'#value' => $jid,
	);
        $form['return_path'] = array(
                '#type' => 'value',
                '#value' => $path,
        );


	return confirm_form($form, $question = t('Are you sure you want to delete Section '.$query['section_name'].'?'), $path, $description= t('This action cannot be undone'), $yes = 'Delete', $no = 'Cancel');



}

function jit_settings_delete_section_form_submit($form, &$form_state){

        $stop = 'stop';

        $jid = $form_state['values']['jid'];
        $return_path = $form_state['values']['return_path'];

        db_delete('jit_settings_sections')
            ->condition('jid',$jid,'=')
            ->execute();


        $form_state['redirect'] = $return_path;
}


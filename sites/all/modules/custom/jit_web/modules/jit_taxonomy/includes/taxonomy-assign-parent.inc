<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



function jit_taxonomy_validate_term($term){
    $validate = TRUE;

    if($term->vocabulary_machine_name !== 'products'){
        return FALSE;
    }

    if($term->name == 'Not In Menu'){
        return FALSE;
    }

    if(property_exists($term,'field_show_in_products_menu')){


        $show_in_menu = $term->field_show_in_products_menu[LANGUAGE_NONE][0]['value'];

        //if the term is programmatically made it is possible that there will be no
        //value for field_show_in_products_menu in which case we should continue to
        //hide from products menu.

        if (!isset($show_in_menu)){

            if($show_in_menu == 1){
                return FALSE;
            }

        }

    }




    return $validate;
}

function jit_taxonomy_taxonomy_term_insert($term){



    if (jit_taxonomy_validate_term($term)){

        $parent_tid = jit_web_get_tid_from_taxonomy_term_name('Not In Menu','products');

        //if we found the Not In Menu Parent, set parent and weight based on children
        //and save it.  Otherwise, we leave it alone.

        if ($parent_tid){

            $children = taxonomy_get_children($parent_tid);
            $children_weights = array();


            foreach ($children as $child) {
                $children_weights[] = $child->weight;

            }

            $max_weight = max($children_weights);

            $term->weight = $max_weight+1;

            $term->parent[0] = $parent_tid;

            taxonomy_term_save($term);
        }




    }


}

function jit_taxonomy_hide_taxonomy_term_in_products_menu($term_name,$vocabulary){
        $arr_terms = taxonomy_get_term_by_name($term_name, $vocabulary);

        if (!empty($arr_terms)) {
        $arr_terms = array_values($arr_terms);

        if(isset($arr_terms[0]->field_show_in_products_menu[LANGUAGE_NONE][0]['value'])){
        $show_in_menu = $arr_terms[0]->field_show_in_products_menu[LANGUAGE_NONE][0]['value'];
        }else{
            $show_in_menu = 0;
        }

        }
        If ($show_in_menu != 1){
            return TRUE;
        }else{
            return FALSE;
        }

}

function jit_taxonomy_taxonomy_menu_insert(&$item){

    if (jit_taxonomy_hide_taxonomy_term_in_products_menu($item['name'],'products')){
        $item['remove']=TRUE;
    }else {
        //if show in menu is checked, then we need to make sure we show the link
        //regardless of the current "remove" value.
        if(isset($item['remove'])){
            unset($item['remove']);
        }

    }

}


function jit_taxonomy_taxonomy_menu_update(&$item){
    if (jit_taxonomy_hide_taxonomy_term_in_products_menu($item['name'],'products')){
        $item['remove']=TRUE;
    }else {
        //if show in menu is checked, then we need to make sure we show the link
        //regardless of the current "remove" value.
        if(isset($item['remove'])){
            unset($item['remove']);
        }

    }

}




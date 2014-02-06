<?php

/**
 * @file
 * Context Block Class Reaction
 */

/**
 * Expose blocks as context reactions.
 */
class context_block_class_reaction_block extends context_reaction_block {

  function options_form($context) {

    $form = parent::options_form($context);

    foreach (element_children($form['blocks']) as $region) {

      foreach ($this->get_blocks($region, $context) as $block) {
        if (!empty($block->context)) {

          $classes = !empty($context->reactions['block']['blocks'][$block->bid]['classes']) ? $context->reactions['block']['blocks'][$block->bid]['classes'] : '';

          // Add our classes field
          $form['blocks'][$region][$block->bid]['classes'] = array(
          '#type' => 'textfield',
          '#size' => '10',
          '#default_value' => $classes,
          );
        }
      }
    }

    return $form;
  }

  /**
   * Options form submit handler.
   */
  function options_form_submit($values) {

    $config = parent::options_form_submit($values);

    // Add class info
    foreach ($config['blocks'] as $bid => $block) {
      $config['blocks'][$bid]['classes'] = $values['blocks'][$block['region']][$bid]['classes'];
    }

    return $config;
  }


  function execute(&$page) {
    parent::execute($page);
  }

}
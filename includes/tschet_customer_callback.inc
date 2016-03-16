<?php
/**
 * @file
 * File for the Tschet Customer list.
 */

/**
 * Constructs the Tschet Customers page.
 */
function tschet_customer_callback() {
  $form = array();
  $form['customer_list'] = array(
    '#tag' => 'div',
    '#attributes' => array(
      'class' => 'range-display',
    ),
    '#value' => tschet_customer_teaser(),
    '#theme' => 'html_tag',
    '#access' => array('access content'),

  );
  return $form;
}

/**
 * Loading node and rendering teaser.
 *
 * @return string
 *   Returns imploded string of rendered HTML for $form display.
 */
function tschet_customer_teaser() {
  // Gather all tschet_customer nodes created.
  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type';
  $result = db_query($sql, array(':type' => 'tschet_customer'));
  $nids = array();
  $contents = array();

  foreach ($result as $row) {
    $nids[] = $row->nid;
  }
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $customer = node_view($node, 'teaser', NULL);
    $contents[$nid] = render($customer);

  }
  $contents = implode($contents);
  return $contents;
}

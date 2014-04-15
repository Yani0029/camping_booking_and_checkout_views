<?php
/**
 * @file
 * camping_booking_and_checkout_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function camping_booking_and_checkout_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'clone_af_booking_cart_form';
  $view->description = 'Display a shopping cart update form.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Klon af Booking cart form';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Shopping cart';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'commerce_display_path' => 'commerce_display_path',
    'line_item_title' => 'line_item_title',
    'commerce_unit_price' => 'commerce_unit_price',
    'edit_quantity' => 'edit_quantity',
    'edit_delete' => 'edit_delete',
    'commerce_total' => 'commerce_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'commerce_display_path' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'line_item_title' => array(
      'align' => '',
      'separator' => '',
    ),
    'commerce_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_quantity' => array(
      'align' => '',
      'separator' => '',
    ),
    'edit_delete' => array(
      'align' => '',
      'separator' => '',
    ),
    'commerce_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* Sidefod: Commerce Ordre: Ordretotal */
  $handler->display->display_options['footer']['order_total']['id'] = 'order_total';
  $handler->display->display_options['footer']['order_total']['table'] = 'commerce_order';
  $handler->display->display_options['footer']['order_total']['field'] = 'order_total';
  /* Forbindelse: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Felt: Amount */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Amount';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if ($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->type == \'product\') {
  $nights = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->field_booking_days[\'und\'][0][\'value\'];
  $quantity = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->quantity;

  if($quantity >= $nights && ($quantity % $nights == 0))  {
    print $quantity/$nights;
  }
  else print $quantity/1;
}
else {
//elseif ($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->type == \'room_booking\'){
  print $quantity = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->quantity/1;
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Felt: Commerce Line item: Display sti */
  $handler->display->display_options['fields']['commerce_display_path']['id'] = 'commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['table'] = 'field_data_commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['field'] = 'commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_display_path']['label'] = '';
  $handler->display->display_options['fields']['commerce_display_path']['exclude'] = TRUE;
  /* Felt: Plads */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Plads';
  $handler->display->display_options['fields']['php']['label'] = 'Plads';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
//print_r($data);
if (isset($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->rooms_booked_unit_id[\'und\'])) {
(int)$unit_id = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->rooms_booked_unit_id[\'und\'][0][\'value\'];

$result = db_query("
SELECT name FROM 
{rooms_units}
WHERE unit_id = $unit_id
")->fetchField();

print $result;
}
else {
  print "";
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Commerce Line Item: Etiket */
  $handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['line_item_label']['label'] = 'Booking';
  $handler->display->display_options['fields']['line_item_label']['alter']['text'] = '[line_item_label] - (Antal [php_1])';
  /* Felt: Commerce Line item: Enhedspris */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Price';
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_unit_price']['alter']['text'] = '[commerce_unit_price] [commerce_unit_price-currency_code] ';
  $handler->display->display_options['fields']['commerce_unit_price']['element_class'] = 'price';
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['type'] = 'commerce_reports_visualization';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Felt: Commerce Line item: Booking Number People */
  $handler->display->display_options['fields']['rooms_booking_number_people']['id'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['table'] = 'field_data_rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['field'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['rooms_booking_number_people']['label'] = 'Voksne';
  $handler->display->display_options['fields']['rooms_booking_number_people']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['rooms_booking_number_people']['delta_limit'] = '1';
  $handler->display->display_options['fields']['rooms_booking_number_people']['delta_offset'] = '0';
  /* Felt: Commerce Line item: Booking Number People */
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['id'] = 'rooms_booking_number_people_1';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['table'] = 'field_data_rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['field'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['label'] = 'Børn';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_reversed'] = TRUE;
  /* Felt: Commerce Line Item: Mængde */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['quantity']['alter']['text'] = '[php_1]';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  $handler->display->display_options['fields']['quantity']['decimal'] = '';
  /* Felt: Commerce Line item: Days */
  $handler->display->display_options['fields']['field_booking_days']['id'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['table'] = 'field_data_field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['field'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['field_booking_days']['label'] = 'Dage';
  $handler->display->display_options['fields']['field_booking_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Commerce Line item: I alt */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_total']['element_class'] = 'price';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  /* Felt: Commerce Line Item: Slet knap */
  $handler->display->display_options['fields']['edit_delete']['id'] = 'edit_delete';
  $handler->display->display_options['fields']['edit_delete']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['edit_delete']['field'] = 'edit_delete';
  $handler->display->display_options['fields']['edit_delete']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['edit_delete']['label'] = 'Remove';
  $handler->display->display_options['fields']['edit_delete']['element_default_classes'] = FALSE;
  /* Felt: Commerce Line item: Booking Options */
  $handler->display->display_options['fields']['rooms_booking_options']['id'] = 'rooms_booking_options';
  $handler->display->display_options['fields']['rooms_booking_options']['table'] = 'field_data_rooms_booking_options';
  $handler->display->display_options['fields']['rooms_booking_options']['field'] = 'rooms_booking_options';
  $handler->display->display_options['fields']['rooms_booking_options']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['rooms_booking_options']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rooms_booking_options']['delta_offset'] = '0';
  /* Sorteringskriterie: Commerce Line Item: Varelinje ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Kontekstuelt filter: Commerce Ordre: Ordre ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['order_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Commerce Line Item: Varelinjen er af en produktvarelinjetype */
  $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
  $handler->display->display_options['filters']['product_line_item_type']['group'] = 0;
  $export['clone_af_booking_cart_form'] = $view;

  $view = new view();
  $view->name = 'clone_af_booking_checkout_form';
  $view->description = 'Display a shopping cart update form.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Klon af Booking checkout form';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Shopping cart';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'rooms_booked_unit_id' => 'rooms_booked_unit_id',
    'php' => 'php',
    'commerce_display_path' => 'commerce_display_path',
    'line_item_label' => 'line_item_label',
    'commerce_total' => 'commerce_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'rooms_booked_unit_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_display_path' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line_item_label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Sidefod: Commerce Line Item: Varelinjeresumé */
  $handler->display->display_options['footer']['line_item_summary']['id'] = 'line_item_summary';
  $handler->display->display_options['footer']['line_item_summary']['table'] = 'commerce_line_item';
  $handler->display->display_options['footer']['line_item_summary']['field'] = 'line_item_summary';
  $handler->display->display_options['footer']['line_item_summary']['label'] = 'Cart summary';
  $handler->display->display_options['footer']['line_item_summary']['info'] = array(
    'quantity' => 0,
    'total' => 'total',
  );
  /* Forbindelse: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Felt: Amount */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Amount';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if ($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->type == \'product\') {
  $nights = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->field_booking_days[\'und\'][0][\'value\'];
  $quantity = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->quantity;
  if ($quantity >= $nights && ($quantity % $nights == 0))
  print $quantity/$nights;
  else print $quantity/1;
}
else {
//elseif ($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->type == \'room_booking\'){
  print $quantity = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->quantity/1;
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Felt: Commerce Line item: Booked Unit ID */
  $handler->display->display_options['fields']['rooms_booked_unit_id']['id'] = 'rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['table'] = 'field_data_rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['field'] = 'rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rooms_booked_unit_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Plads';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
//print_r($data);
if (isset($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->rooms_booked_unit_id[\'und\'])) {

  (int)$unit_id = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->rooms_booked_unit_id[\'und\'][0][\'value\'];

  $result = db_query("
    SELECT name FROM 
    {rooms_units}
    WHERE unit_id = $unit_id
   ")->fetchField();

  print $result;
}
else {
  print "";
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Commerce Line item: Display sti */
  $handler->display->display_options['fields']['commerce_display_path']['id'] = 'commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['table'] = 'field_data_commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['field'] = 'commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_display_path']['label'] = '';
  $handler->display->display_options['fields']['commerce_display_path']['exclude'] = TRUE;
  /* Felt: Commerce Line Item: Etiket */
  $handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['line_item_label']['label'] = 'Booking';
  /* Felt: Commerce Line item: Days */
  $handler->display->display_options['fields']['field_booking_days']['id'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['table'] = 'field_data_field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['field'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['field_booking_days']['label'] = 'Dage';
  $handler->display->display_options['fields']['field_booking_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Commerce Line Item: Mængde */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['quantity']['alter']['text'] = '[php_1]';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Felt: Commerce Line item: I alt */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_total']['element_class'] = 'price';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  /* Sorteringskriterie: Commerce Line Item: Varelinje ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Kontekstuelt filter: Commerce Ordre: Ordre ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['order_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Commerce Line Item: Varelinjen er af en produktvarelinjetype */
  $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
  $handler->display->display_options['filters']['product_line_item_type']['group'] = 0;
  $export['clone_af_booking_checkout_form'] = $view;

  $view = new view();
  $view->name = 'clone_af_line_items';
  $view->description = 'Display a set of line items in a table.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_line_item';
  $view->human_name = 'Klon af Line items';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'line_item_id' => 'line_item_id',
    'php' => 'php',
    'type' => 'type',
    'line_item_title' => 'line_item_title',
    'line_item_label' => 'line_item_title',
    'commerce_unit_price' => 'commerce_unit_price',
    'rooms_booking_number_people' => 'rooms_booking_number_people',
    'rooms_booking_number_people_1' => 'rooms_booking_number_people_1',
    'quantity' => 'quantity',
    'rooms_booking_options' => 'rooms_booking_options',
    'commerce_total' => 'commerce_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'line_item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line_item_title' => array(
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'line_item_label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rooms_booking_number_people' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rooms_booking_number_people_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'quantity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rooms_booking_options' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Opførsel ved ingen resultater: Global: Tekstområde */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty line item text.';
  $handler->display->display_options['empty']['area']['content'] = 'No line items found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Felt: Amount */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Amount';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php

if ($data->_field_data[\'line_item_id\'][\'entity\']->type == \'product\') {
  $nights = $data->_field_data[\'line_item_id\'][\'entity\']->field_booking_days[\'und\'][0][\'value\'];
  $quantity = $data->_field_data[\'line_item_id\'][\'entity\']->quantity;
  if($quantity >= $nights &&  ($quantity % $nights == 0))
  print $quantity/$nights;
  else print $quantity/1;
}
else {
//elseif ($data->_field_data[\'line_item_id\'][\'entity\']->type == \'room_booking\'){
  print $quantity = $data->_field_data[\'line_item_id\'][\'entity\']->quantity/1;
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Felt: Commerce Line Item: Varelinje ID */
  $handler->display->display_options['fields']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['label'] = 'ID';
  $handler->display->display_options['fields']['line_item_id']['exclude'] = TRUE;
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Plads';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
//print_r($data);
if (isset($data->_field_data[\'line_item_id\'][\'entity\']->rooms_booked_unit_id[\'und\'][0][\'value\']) && (int)$unit_id = $data->_field_data[\'line_item_id\'][\'entity\']->rooms_booked_unit_id[\'und\'][0][\'value\']){
 $result = db_query("
  SELECT name FROM 
  {rooms_units}
  WHERE unit_id = $unit_id
 ")->fetchField();

 print $result;
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Commerce Line Item: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Felt: Commerce Line Item: Titel */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  /* Felt: Commerce Line Item: Etiket */
  $handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['exclude'] = TRUE;
  /* Felt: Commerce Line item: Enhedspris */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  /* Felt: Commerce Line item: Booking Number People */
  $handler->display->display_options['fields']['rooms_booking_number_people']['id'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['table'] = 'field_data_rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['field'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['label'] = 'Voksne';
  $handler->display->display_options['fields']['rooms_booking_number_people']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['rooms_booking_number_people']['delta_limit'] = '1';
  $handler->display->display_options['fields']['rooms_booking_number_people']['delta_offset'] = '0';
  /* Felt: Commerce Line item: Booking Number People */
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['id'] = 'rooms_booking_number_people_1';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['table'] = 'field_data_rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['field'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['label'] = 'Børn';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_reversed'] = TRUE;
  /* Felt: Commerce Line item: Days */
  $handler->display->display_options['fields']['field_booking_days']['id'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['table'] = 'field_data_field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['field'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['label'] = 'Dage';
  $handler->display->display_options['fields']['field_booking_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Commerce Line Item: Mængde */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['quantity']['alter']['text'] = '[php_1]';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Felt: Commerce Line item: Booking Options */
  $handler->display->display_options['fields']['rooms_booking_options']['id'] = 'rooms_booking_options';
  $handler->display->display_options['fields']['rooms_booking_options']['table'] = 'field_data_rooms_booking_options';
  $handler->display->display_options['fields']['rooms_booking_options']['field'] = 'rooms_booking_options';
  $handler->display->display_options['fields']['rooms_booking_options']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rooms_booking_options']['delta_offset'] = '0';
  /* Felt: Commerce Line item: I alt */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Sorteringskriterie: Commerce Line Item: Varelinje ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  /* Kontekstuelt filter: Commerce Line Item: Varelinje ID */
  $handler->display->display_options['arguments']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['arguments']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['line_item_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['line_item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['line_item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['line_item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['line_item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['line_item_id']['break_phrase'] = TRUE;
  /* Filterkriterie: Commerce Line Item: Varelinjen er af en produktvarelinjetype */
  $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
  $export['clone_af_line_items'] = $view;

  $view = new view();
  $view->name = 'clone_af_shopping_cart_form';
  $view->description = 'Display a shopping cart update form.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Klon af Shopping cart form';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Shopping cart';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'commerce_display_path' => 'commerce_display_path',
    'line_item_title' => 'line_item_title',
    'commerce_unit_price' => 'commerce_unit_price',
    'edit_quantity' => 'edit_quantity',
    'edit_delete' => 'edit_delete',
    'commerce_total' => 'commerce_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'commerce_display_path' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'line_item_title' => array(
      'align' => '',
      'separator' => '',
    ),
    'commerce_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_quantity' => array(
      'align' => '',
      'separator' => '',
    ),
    'edit_delete' => array(
      'align' => '',
      'separator' => '',
    ),
    'commerce_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* Sidefod: Commerce Line Item: Varelinjeresumé */
  $handler->display->display_options['footer']['line_item_summary']['id'] = 'line_item_summary';
  $handler->display->display_options['footer']['line_item_summary']['table'] = 'commerce_line_item';
  $handler->display->display_options['footer']['line_item_summary']['field'] = 'line_item_summary';
  $handler->display->display_options['footer']['line_item_summary']['label'] = 'Cart summary';
  $handler->display->display_options['footer']['line_item_summary']['links'] = array(
    'view_cart' => 'view_cart',
    'checkout' => 'checkout',
  );
  $handler->display->display_options['footer']['line_item_summary']['info'] = array(
    'quantity' => 0,
    'total' => 'total',
  );
  /* Forbindelse: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Felt: Commerce Line item: Booked Unit ID */
  $handler->display->display_options['fields']['rooms_booked_unit_id']['id'] = 'rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['table'] = 'field_data_rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['field'] = 'rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rooms_booked_unit_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Plads';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
//print_r($data);
if (isset($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->rooms_booked_unit_id[\'und\'])) {
  (int)$unit_id = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->rooms_booked_unit_id[\'und\'][0][\'value\'];

  $result = db_query("
    SELECT name FROM {rooms_units}
    WHERE unit_id = $unit_id
    ")->fetchField();

   print $result;
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Commerce Line item: Display sti */
  $handler->display->display_options['fields']['commerce_display_path']['id'] = 'commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['table'] = 'field_data_commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['field'] = 'commerce_display_path';
  $handler->display->display_options['fields']['commerce_display_path']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_display_path']['label'] = '';
  $handler->display->display_options['fields']['commerce_display_path']['exclude'] = TRUE;
  /* Felt: Commerce Line Item: Titel */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['line_item_title']['label'] = 'Product';
  $handler->display->display_options['fields']['line_item_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['line_item_title']['alter']['path'] = '[commerce_display_path]';
  /* Felt: Commerce Line item: Enhedspris */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Price';
  $handler->display->display_options['fields']['commerce_unit_price']['element_class'] = 'price';
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Felt: Commerce Line item: Booking Number People */
  $handler->display->display_options['fields']['rooms_booking_number_people']['id'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['table'] = 'field_data_rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['field'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['rooms_booking_number_people']['label'] = 'Voksne';
  $handler->display->display_options['fields']['rooms_booking_number_people']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rooms_booking_number_people']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['rooms_booking_number_people']['delta_limit'] = '1';
  $handler->display->display_options['fields']['rooms_booking_number_people']['delta_offset'] = '0';
  /* Felt: Commerce Line item: Booking Number People */
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['id'] = 'rooms_booking_number_people_1';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['table'] = 'field_data_rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['field'] = 'rooms_booking_number_people';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['label'] = 'Børn';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['rooms_booking_number_people_1']['delta_reversed'] = TRUE;
  /* Felt: Commerce Line item: Days */
  $handler->display->display_options['fields']['field_booking_days']['id'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['table'] = 'field_data_field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['field'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['field_booking_days']['label'] = 'Dage';
  $handler->display->display_options['fields']['field_booking_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Commerce Line Item: Mængde tekstfelt */
  $handler->display->display_options['fields']['edit_quantity']['id'] = 'edit_quantity';
  $handler->display->display_options['fields']['edit_quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['edit_quantity']['field'] = 'edit_quantity';
  $handler->display->display_options['fields']['edit_quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['edit_quantity']['label'] = '';
  $handler->display->display_options['fields']['edit_quantity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_quantity']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['edit_quantity']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['edit_quantity']['element_label_colon'] = FALSE;
  /* Felt: Commerce Line item: I alt */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_total']['element_class'] = 'price';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  /* Felt: Commerce Line Item: Slet knap */
  $handler->display->display_options['fields']['edit_delete']['id'] = 'edit_delete';
  $handler->display->display_options['fields']['edit_delete']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['edit_delete']['field'] = 'edit_delete';
  $handler->display->display_options['fields']['edit_delete']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['edit_delete']['label'] = 'Remove';
  /* Sorteringskriterie: Commerce Line Item: Varelinje ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Kontekstuelt filter: Commerce Ordre: Ordre ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['order_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Commerce Line Item: Varelinjen er af en produktvarelinjetype */
  $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
  $handler->display->display_options['filters']['product_line_item_type']['group'] = 0;
  $export['clone_af_shopping_cart_form'] = $view;

  $view = new view();
  $view->name = 'clone_af_shopping_cart_summary';
  $view->description = 'Cart line item summary displayed during checkout.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Klon af Shopping cart summary';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Shopping cart';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'line_item_title' => 'line_item_title',
    'commerce_unit_price' => 'commerce_unit_price',
    'quantity' => 'quantity',
    'commerce_total' => 'commerce_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'line_item_title' => array(
      'align' => '',
      'separator' => '',
    ),
    'commerce_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'quantity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'commerce_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
    ),
  );
  /* Sidefod: Commerce Ordre: Ordretotal */
  $handler->display->display_options['footer']['order_total']['id'] = 'order_total';
  $handler->display->display_options['footer']['order_total']['table'] = 'commerce_order';
  $handler->display->display_options['footer']['order_total']['field'] = 'order_total';
  /* Forbindelse: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Felt: Amount */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Amount';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if ($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->type == \'product\') {
  $nights = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->field_booking_days[\'und\'][0][\'value\'];
  $quantity = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->quantity;
  if($quantity % $nights == 0)
  print $quantity/$nights;
  else print $quantity/1;
}
else {
//elseif ($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->type == \'room_booking\'){
  print $quantity = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->quantity/1;
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Felt: Commerce Line item: Booked Unit ID */
  $handler->display->display_options['fields']['rooms_booked_unit_id']['id'] = 'rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['table'] = 'field_data_rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['field'] = 'rooms_booked_unit_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['rooms_booked_unit_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rooms_booked_unit_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Plads';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
//print_r($data);
if (isset($data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->rooms_booked_unit_id[\'und\'])) {
  (int)$unit_id = $data->_field_data[\'commerce_line_item_field_data_commerce_line_items_line_item_\'][\'entity\']->rooms_booked_unit_id[\'und\'][0][\'value\'];

  $result = db_query("
   SELECT name FROM 
  {rooms_units}
  WHERE unit_id = $unit_id
  ")->fetchField();

  print $result;
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Felt: Commerce Line Item: Titel */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['line_item_title']['label'] = 'Product';
  /* Felt: Commerce Line item: Enhedspris */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Price';
  $handler->display->display_options['fields']['commerce_unit_price']['element_class'] = 'price';
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Felt: Commerce Line item: Days */
  $handler->display->display_options['fields']['field_booking_days']['id'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['table'] = 'field_data_field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['field'] = 'field_booking_days';
  $handler->display->display_options['fields']['field_booking_days']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['field_booking_days']['label'] = 'Dage';
  /* Felt: Commerce Line Item: Mængde */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['quantity']['alter']['text'] = '[php_1]';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Felt: Commerce Line item: I alt */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_total']['element_class'] = 'price';
  $handler->display->display_options['fields']['commerce_total']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Sorteringskriterie: Commerce Line Item: Varelinje ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Kontekstuelt filter: Commerce Ordre: Ordre ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['order_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Commerce Line Item: Varelinjen er af en produktvarelinjetype */
  $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
  $handler->display->display_options['filters']['product_line_item_type']['group'] = 0;
  $export['clone_af_shopping_cart_summary'] = $view;

  $view = new view();
  $view->name = 'rooms_update';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'rooms_units';
  $view->human_name = 'Rooms update';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Rooms update';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'unit_id' => 'unit_id',
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'unit_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Felt: Masse-handlinger: Bookable Units */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'rooms_units';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'hytter::rooms_booking_unit_options' => 'hytter::rooms_booking_unit_options',
          'hytter::field_body' => 'hytter::field_body',
          'hytter::field_hytter_billed' => 'hytter::field_hytter_billed',
          'enheder::rooms_booking_unit_options' => 'enheder::rooms_booking_unit_options',
          'enheder::field_billed' => 'enheder::field_billed',
          'enheder::field_body' => 'enheder::field_body',
          'teltplads::rooms_booking_unit_options' => 'teltplads::rooms_booking_unit_options',
          'teltplads::field_tent_pic' => 'teltplads::field_tent_pic',
          'teltplads::field_body' => 'teltplads::field_body',
          'hytter_2::rooms_booking_unit_options' => 'hytter_2::rooms_booking_unit_options',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Felt: Bookable Units: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'rooms_units';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Navn';
  /* Felt: Bookable Units: Bookable units ID */
  $handler->display->display_options['fields']['unit_id']['id'] = 'unit_id';
  $handler->display->display_options['fields']['unit_id']['table'] = 'rooms_units';
  $handler->display->display_options['fields']['unit_id']['field'] = 'unit_id';
  /* Filterkriterie: Bookable Units: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'rooms_units';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/rooms-update';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Rooms Update';
  $handler->display->display_options['menu']['description'] = 'Opdater enheder';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['rooms_update'] = $view;

  return $export;
}

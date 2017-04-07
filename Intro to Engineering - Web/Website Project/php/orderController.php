<?php
/**
 * orderController class
 *
 * @author Reid Wixom
 */

class orderController {

	var $orderStore;

	function __construct() {
		$this->orderStore = new OrderStore();
	}

	public function getOpenOrders() {
		return $this->orderStore->getOpenOrders();
	}
	public function getOrder($id) {
		return $this->orderStore->getOrder($id);
	}
	public function setAsCompleted($id) {
		return $this->orderStore->setAsCompleted($id);
	}




}



 ?>
<?php
/*
 *	recievingDeskController
*/


class receivingDeskController{
	var $recDeskContr;
	function __construct()
	{
		$this->recDeskContr = new productStore();
	}
	public function getProducts()
	{
		return $this ->recDeskContr->getProducts();
	}
	public function getProduct($id)
	{
		return $this->recDeskContr->getProduct($id);
	}
	public function updateProductInventory($id, $qty)
	{
		return $this->recDeskContr->updateProductInventory($id, $qty);
	}
}

?>
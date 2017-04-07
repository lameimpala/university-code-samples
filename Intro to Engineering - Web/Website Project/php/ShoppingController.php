<?php
/**
 * ShoppingController class
 *
 * @author Reid Wixom
 */

class ShoppingController {

	var $shippingFee = 5;
	var $taxRate = .06;

	var $orderStore;
	var $productStore;

	function __construct() {
		$this->productStore = new ProductStore();
		$this->orderStore = new OrderStore();
	}

	public function getProducts() {
		return $this->productStore->getProducts();
	}

	public function getProduct($id) {
		return $this->productStore->getProduct($id);
	}
	public function submitOrder($transID, $custName, $address, $prodID, $qty) {
		return $this->orderStore->submitOrder($transID, $custName, $address, $prodID, $qty);
	}
	public function searchByDescription($string) {
		return $this->productStore->searchByDescription($string);
	}

	public function processCC($ccNum, $ccExpM, $ccExpY, $cost, $custName) {
		$fp = fsockopen( "udp://blitz.cs.niu.edu", 4445, $errno, $errstr );
		if (!$fp) die("$errstr ($errno)<br>");
		$message = $ccNum . ':' . $ccExpM . '/' . $ccExpY . ':' . $cost . ':' . $custName;
		fwrite( $fp, $message ) or die("write failed<br>");
		$response = fread($fp, 1024);
		return $response;
	}

	public function calculateCost($id, $qty) {
		$product = $this->getProduct($id);

		$price = $product->price * $qty;
		$price = $price * (1 + $this->taxRate);
		$price = $price + $this->shippingFee;

		return $price;
	}

	//testing
	public function calculateCostNoFee($id,$qty){
		$product = $this->getProduct($id);
		$price = $product->price * $qty;
		return $price;		
	}

	public function getShippingFee() {
		return $this->shippingFee;
	}
	public function getSalesTax() {
		return $this->taxRate;
	}

	public function setShippingFee($fee) {
		$this->shippingFee = $fee;
	}
	public function setSalesTax($tax) {
		$this->taxRate = $tax;
	}


}



 ?>
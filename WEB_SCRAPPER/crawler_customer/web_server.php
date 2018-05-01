<?php

class ResponseServer{
  private static $conn = null;

  private function __construct() {}

  private function __clone() {}

  public static function construct(){
    if(self::$conn == null){
      $conn = new mysqli("localhost", "root", "s400", "URIOJ");
    }
    // Check connection
    if ($conn->connect_error){
        die("Connection failed: " . $conn->connect_error);
    }
    //echo "SUCESS";
    return $conn;
  }

  public function getUserStatById($userId){

      $sql = "SELECT * FROM account WHERE userId = " . $userId . " GROUP BY ;";

          $result = $this->con->query($sql);

      $resultSet = array();

      if($result == null || ($result != null && $result->num_rows == 0)){
        return null;
      }

      while($row = $result->fetch_assoc()){
        $account_var = new AccountModel();

          $account_var->setId($row["id"]);
          $account_var->setUserId($row["userId"]);
          $account_var->setAppAlias($row["app_alias"]);
          $account_var->setAppAddress($row["app_address"]);
          $account_var->setAssociatedAccount($row["associated_account"]);
          $account_var->setLogin($row["login"]);
          $account_var->setPassword($row["password"]);
            
            array_push($resultSet,$account_var);
          }
      return $resultSet;
      }

}



?>
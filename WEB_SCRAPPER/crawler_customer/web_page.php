<!DOCTYPE html>
<!-- @LUKASAVICUS - 2015 - God be Praised-->
<html>
    
<!-- ===================================================== Commom HEAD ====================================================== -->
  <head>
    <meta charset="UTF-8">
    <title>URI Dashboard API</title>    

    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css" integrity="sha384-PsH8R72JQ3SOdhVi3uxftmaW6Vc51MKb0q5P2rRUpPvrszuE4W1povHYgTpBfshb" crossorigin="anonymous">

    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ" crossorigin="anonymous"></script>

  </head>
  <body>
    <div style="visibility:none">
        <table id="data-table" class="table table-hover" width="90" height="90">
        </table>
    </div>
  </body>
  <script type="text/javascript">
      var TABLE = document.getElementById('data-table');
      var TYPES = ["Iniciante", "Ad-Hoc", "Strings ", "Estruturas e Bibliotecas", "Matemática", "Paradigmas", "Grafos", "Geometria Computacional", "SQL"];
      var qnt_lvls = 10;

      var DATA;

      // DATA["iniciante"][0] = 1;
      // DATA["iniciante"][1] = 2;
      // DATA["iniciante"][2] = 3;

    var data_insertion = function(DATA, TABLE){

        var size_x = DATA.length;
        var size_y = DATA[0].length;

        for(var i = 0; i < size_x; i++) {
            var row = TABLE.insertRow(i);
            for(var j = 0; j < size_y; j++) {
                var cell = row.insertCell(j);
                cell.innerHTML = DATA[i][j];
            }
        }
    };

      var data_insert = function(DATA){

        var row = TABLE.insertRow(0);

        var cell = row.insertCell(0);
        cell.innerHTML = "X";

        for (var i = 0; i < qnt_lvls; i++) {
            var cell = row.insertCell(i+1);
            cell.innerHTML = (i+1);
        }

        var cell = row.insertCell(qnt_lvls+1);
        cell.innerHTML = "Total";

        for(var i = 0; i < TYPES.length; i++) {
            var row = TABLE.insertRow(i+1);

            var cell = row.insertCell(0);
            cell.innerHTML = TYPES[i];

            for(var j = 0; j < qnt_lvls; j++) {
                var cell = row.insertCell(j+1);
                cell.innerHTML = (j+1);
            }
            var cell = row.insertCell(qnt_lvls+1);
            cell.innerHTML = (j+1);

        }

        var row = TABLE.insertRow(TYPES.length+1);

        var cell = row.insertCell(0);
        cell.innerHTML = "Total";

        for(var j = 0; j < qnt_lvls; j++) {
            var cell = row.insertCell(j+1);
            cell.innerHTML = (j+1);
        }

        var cell = row.insertCell(qnt_lvls+1);
        cell.innerHTML = "Sum";

      };

      data_insert([]);

  </script>
</html>
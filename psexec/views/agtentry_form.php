
<tr>
    <td>
        Enter property name to <?= $title ?>
    </td>
</tr>
<tr>
  <td >
      <div id="middle">

        <form action="agtentry.php" method="post">
            <fieldset>

                <div class="form-group">
                    <select class="form-control" name="place_name">
                    <option disabled selected value="">Property Name</option>
    
                    <?php foreach ($positions as $position)    { ?>
                    <option value="<?=$position["place_name"] ?>"> <?=$position["place_name"] ?>
                    </option>
                    <?php } ?>
    
                    </select>                
                </div>
        
                <div class="form-group">
                    <button class="btn btn-default" type="submit">
                        <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                        ENTER
                    </button>
                </div>
            </fieldset>
        </form>

        <?php //dump($rows); // DEBUG ?>
      </div>



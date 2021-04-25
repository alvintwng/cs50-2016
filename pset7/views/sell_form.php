<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <!--input autocomplete="off" autofocus class="form-control" name="symbol" placeholder="Symbol" type="text"/-->
            <select class="form-control" name="symbol">
                <option disabled selected value="">Symbol</option>

                <?php foreach ($positions as $position)    { ?>
                <option value="<?=$position["symbol"] ?>"> <?=$position["symbol"] ?>
                </option>
                <?php } ?>

            </select>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
</form>




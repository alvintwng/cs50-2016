<tr>
  <td >
    <div id="middle" style="width:200px ;padding:15px;margin: 0 auto;">
      <form action="login.php" method="post" class="form-signin" >
        <h4 class="form-signin-heading">Please sign in</h4>
        <label for="Username" class="sr-only">Username</label>
        <input type="text" name="username" class="form-control" placeholder="Username" required autofocus>
        <label for="Password" class="sr-only">Password</label>
        <input type="password" name="password" class="form-control" placeholder="Password" required>
        <div class="checkbox">
          <label>
            <input type="checkbox" value="remember-me"> Remember me
          </label>
        </div>
        <button class="btn btn-lg btn-primary btn-block" type="submit">Sign in</button>
      </form>

    </div>
  </td>
</tr>
<!--
    <div class="container">

      <form class="form-signin">
        <h2 class="form-signin-heading">Please sign in</h2>
        <label for="inputEmail" class="sr-only">Email address</label>
        <input type="email" id="inputEmail" class="form-control" placeholder="Email address" required autofocus>
        <label for="inputPassword" class="sr-only">Password</label>
        <input type="password" id="inputPassword" class="form-control" placeholder="Password" required>
        <div class="checkbox">
          <label>
            <input type="checkbox" value="remember-me"> Remember me
          </label>
        </div>
        <button class="btn btn-lg btn-primary btn-block" type="submit">Sign in</button>
      </form>



was:

        <form action="login.php" method="post">
            <fieldset>
                <div class="form-group">
                    <input autocomplete="off" autofocus class="form-control" name="username" placeholder="Username" type="text"/>
                </div>
                <div class="form-group">
                    <input class="form-control" name="password" placeholder="Password" type="password"/>
                </div>
                <div class="form-group">
                    <button class="btn btn-default" type="submit">
                        <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                        Log In
                    </button>
                </div>
            </fieldset>
        </form>
-->
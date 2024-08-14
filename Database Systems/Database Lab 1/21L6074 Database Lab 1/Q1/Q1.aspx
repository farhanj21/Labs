<!DOCTYPE html>
<html>
<head>
<title>Sample Form</title>
</head>
<body>

<h2>To illustrate form based tags</h2>
<form action="/submit_form" method="post">
  <label for="text">This is a text box to enter any text:</label><br>
  <input type="text" id="text" name="text"><br><br>

  <label for="password">This is a text box to enter password:</label><br>
  <input type="password" id="password" name="password"><br><br>

  <label for="textarea">This is a text area to enter large text:</label><br>
  <textarea id="textarea" name="textarea" rows="4" cols="50"></textarea><br><br>

  <input type="button" value="Click"><br><br>

  <label>Radio Options:</label><br>
  <input type="radio" id="yes" name="radio_option" value="yes">
  <label for="yes">YES</label><br>
  <input type="radio" id="no" name="radio_option" value="no">
  <label for="no">NO</label><br><br>

  <label>Checkbox Options:</label><br>
  <input type="checkbox" id="sunday" name="day" value="Sunday">
  <label for="sunday">Sunday</label>
  <input type="checkbox" id="monday" name="day" value="Monday">
  <label for="monday">Monday</label>
  <input type="checkbox" id="tuesday" name="day" value="Tuesday">
  <label for="tuesday">Tuesday</label><br><br>

  <label for="cars">Menu driven options:</label><br>
  <select id="cars" name="cars">
    <option value="volvo">Volvo</option>
    <option value="saab">Saab</option>
    <option value="fiat">Fiat</option>
    <option value="audi">Audi</option>
  </select><br><br>

  <input type="submit" value="Submit">
</form>

</body>
</html>

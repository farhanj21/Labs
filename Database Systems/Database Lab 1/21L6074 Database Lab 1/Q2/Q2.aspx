<!DOCTYPE html>
<html>
<head>  

    <body style="background-color:lightgrey;">
    <style>
        h1
        {
            color : blue;
            font-size: 50px;
        }
        p
        {
            color : purple;
            font-size: 17px;
        }

        .submit-button 
        {
            font-size: 16px;
            padding: 3px 12px;
            background-color: transparent;
            border: 2px solid blue;
            color: blue;
            border-radius: 25px;
            box-shadow: 0 0 10px purple;
            transition: all 0.3s ease-in-out;
        }

        .submit-button:hover 
        {
            background-color: blue;
            color: white;
            cursor: pointer;
        }

         .submit-button1 
        {
            font-size: 16px;
            padding: 3px 12px;
            background-color: transparent;
            border: 2px solid red;
            color: red;
            border-radius: 25px;
            box-shadow: 0 0 10px purple;
            transition: all 0.3s ease-in-out;
        }
        .submit-button1:hover 
        {
            background-color: red;
            color: white;
            cursor: pointer;
        }
        select
        {
            border : 2px solid blue;
            box-shadow : 0 0 10px blue; 
        }
        input[type="text"]
        {
            border: 2px solid blue;
            box-shadow: 0 0 10px green;
        }

    </style>
</head>

<script>
    function convertToRupees() {
        let totalRupees = document.getElementById("rupeeto").value;
        let curr = document.getElementById("curr").value;
        let totalConverted;
        if (curr == "Dollar") {
            totalConverted = totalRupees / 282;
        } else if (curr == "Euro") {
            totalConverted = totalRupees / 308;
        } else if (curr == "Pound") {
            totalConverted = totalRupees / 354;
        }
        document.getElementById("rto").value = totalConverted;
        document.getElementById("chosen").value = curr;
    }

    function convertFromRupees() {
        let currencyAmount = document.getElementById("torupee").value;
        let curr = document.getElementById("curr").value;
        let totalConverted;
        if (curr == "Dollar") {
            totalConverted = currencyAmount * 282;
        } else if (curr == "Euro") {
            totalConverted = currencyAmount * 308;
        } else if (curr == "Pound") {
            totalConverted = currencyAmount * 354;
        }
        document.getElementById("tor").value = totalConverted;
        document.getElementById("chosen").value = curr;
    }

    function resetValues() {
        document.getElementById("rupeeto").value = "";
        document.getElementById("rto").value = "";
        document.getElementById("torupee").value = "";
        document.getElementById("tor").value = "";
        document.getElementById("curr").value = "sel";
        document.getElementById("chosen").value = "";
        document.getElementById("program").value = "Zoya Arif";
    }
</script>

<body>
    <h1>Currency Converting Website</h1>

    <p>
       Dollar Rate: 282 Rupees<br />
       Euro Rate: 308 Rupees <br />
       Pound Rate: 354 Rupees<br /><br />

        <label for="country">Select Currency Medium:</label> 
            <select name="curr" id="curr">
                <option value="sel">Select</option>
                <option value="Dollar">Dollar</option>
                <option value="Euro">Euro</option>
                <option value="Pound">Pound</option>
            </select> <br><br>

         <label for="rupeeto">Please Enter Amount in Rupees to Convert to your Selected Medium:</label>
         <input type="text" id="rupeeto" name="rupeeto"> <br /><br />

         <button class="submit-button" onclick="convertToRupees()">Convert Rupees to Selected Medium</button><br /><br />

         <label for="rto">Amount from Rupees to your choosen medium:</label>
         <input type="text" id="rto" name="rto"> <br><br>
         
          <label for="torupee">Please Enter Amount in your choosen medium to convert to Rupees:</label>
         <input type="text" id="torupee" name="torupee"> <br /><br />

         <button class="submit-button" onclick="convertFromRupees()">Convert from Selected Medium to Rupees</button><br /><br />

         <label for="rto">Amount from your choosen medium to Rupees:</label>
         <input type="text" id="tor" name="tor"> <br><br>

         <label for="rto">Your Previous Chosen Medium was:</label>
         <input type="text" id="chosen" name="chosen"> <br><br>

         <label for="rto">Programmed by: </label>
         <input type="text" id="program" name="program"> <br><br>

          <button class="submit-button1" onclick="resetValues()">Reset</button><br /><br />

         

     </p>

      

</body>
</html>
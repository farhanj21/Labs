const express = require('express');
const bodyParser = require('body-parser');
const productsRouter = require('./productsRouter'); 

const app = express();
const port = 3000;

app.use(bodyParser.json());
app.use('/products', productsRouter);

app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});

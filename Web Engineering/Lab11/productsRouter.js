// productsRouter.js
const express = require('express');
const router = express.Router();

let products = []; 

router.get('/', (req, res) => {
  res.json(products);
});

router.get('/:id', (req, res) => {
  const product = products.find(p => p.id === req.params.id);
  if (product) {
    res.json(product);
  } else {
    res.status(404).send('Product not found');
  }
});

router.post('/', (req, res) => {
  const product = {
    id: Date.now().toString(),
    name: req.body.name,
    price: req.body.price
  };
  products.push(product);
  res.status(201).send(product);
});

router.put('/:id', (req, res) => {
  const index = products.findIndex(p => p.id === req.params.id);
  if (index !== -1) {
    products[index] = { ...products[index], ...req.body };
    res.send(products[index]);
  } else {
    res.status(404).send('Product not found');
  }
});

router.delete('/:id', (req, res) => {
  const index = products.findIndex(p => p.id === req.params.id);
  if (index !== -1) {
    products.splice(index, 1);
    res.status(204).send();
  } else {
    res.status(404).send('Product not found');
  }
});

module.exports = router;

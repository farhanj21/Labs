const fs = require('fs');

const oldFilePath = './new_page.html';
const newFilePath = './index.html';

fs.rename(oldFilePath, newFilePath, (err) => {
  if (err) {
    console.log('Error:', err);
  } else {
    console.log(`Renamed ${oldFilePath} to ${newFilePath}`);
  }
});
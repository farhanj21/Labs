const fs = require('fs');

const oldFilePath = './old_page.html';
const newFilePath = './new_page.html';

fs.rename(oldFilePath, newFilePath, (err) => {
  if (err) {
    console.log('Error:', err);
  } else {
    console.log(`Successfully renamed ${oldFilePath} to ${newFilePath}`);
  }
});
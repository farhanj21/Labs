const fs = require('fs');

const filePath = './obsolete_page.html';

fs.unlink(filePath, (err) => {
  if (err) {
    if (err.code === 'ENOENT') {
      console.log('Error:', err.code);
    } else {
      console.log('Error:', err);
    }
  } else {
    console.log(`Successfully deleted ${filePath}`);
  }
});
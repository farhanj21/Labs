const fs = require('fs');
const path = require('path');

const directoryPath = './html_backup';

fs.readdir(directoryPath, (err, files) => {
  if (err) {
    console.log('Error:', err);
  } else {
    files.forEach(file => {
      if (path.extname(file) === '.html') {
        const timestamp = new Date().getTime();
        const newFileName = `${timestamp}_${file}`;
        const oldFilePath = path.join(directoryPath, file);
        const newFilePath = path.join(directoryPath, newFileName);

        fs.rename(oldFilePath, newFilePath, (err) => {
          if (err) {
            console.log('Error:', err);
          } else {
            console.log(`Successfully renamed ${oldFilePath} to ${newFilePath}`);
          }
        });
      }
    });
  }
});
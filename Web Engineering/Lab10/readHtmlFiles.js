const fs = require('fs');
const path = require('path');

const htmlFilesDir = './html_files';

fs.readdir(htmlFilesDir, (err, files) => {
  if (err) {
    console.error('Error reading:', err);
    return;
  }

  files.forEach(file => {
    const filePath = path.join(htmlFilesDir, file);

    if (path.extname(filePath) === '.html') {
      fs.readFile(filePath, 'utf8', (err, data) => {
        if (err) {
          console.error('Error reading file:', err);
          return;
        }

        const imgTags = data.match(/<img[^>]*>/g);
        const numImgTags = imgTags ? imgTags.length : 0;

        console.log(`${filePath}: ${numImgTags} <img> tags found`);
      });
    }
  });
});
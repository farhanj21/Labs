const fs = require('fs');

const originalContent = fs.readFileSync('about.html', 'utf-8');

const keyword = 'old-keyword';
const replacement = 'new-keyword';

const newContent = originalContent.replace(new RegExp(keyword, 'g'), replacement);

fs.writeFileSync('about.html', newContent, 'utf-8');

console.log(`Updated the about.html file by replacing "${keyword}" with "${replacement}"`);
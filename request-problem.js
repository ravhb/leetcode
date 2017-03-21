var fs = require('fs');
var request = require('request');
var cheerio = require('cheerio');

var urls = [
  'https://leetcode.com/problems/linked-list-random-node/#/description',
];

urls.forEach((url) => {
  request(url, (err, response, body) => {
    console.log(url, err);
    var $ = cheerio.load(body);
    var textArr = $('.question-title h3').text().trim().split('. ');
    var no = textArr[0];
    var title = textArr[1];
    var difficulty = $('.question-info li').eq(2).text().split(': ').pop();

    var folderPath = `Algorithms/${title}`;
    var filePath = `${folderPath}/README.md`;


    fs.mkdir(folderPath, (err) => {
      fs.open(filePath, 'wx', (err) => {
        var content = [
          `# [${title}](${url})`,
          `###### No:\`${no}\``,
          `###### Difficulty:\`${difficulty}\``,
          '## JavaScript',
          '',
          '',
          '```js',
          '```',
        ].join('\r\n') + '\r\n';

        fs.writeFile(filePath, content);
      });
    });
  });
});

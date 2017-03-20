var fs = require('fs');
var request = require('request');
var cheerio = require('cheerio');

var urls = [
  'https://leetcode.com/problems/longest-common-prefix/#/description',
  'https://leetcode.com/problems/divide-two-integers/#/description',
  'https://leetcode.com/problems/next-permutation/#/description',
  'https://leetcode.com/problems/search-in-rotated-sorted-array/#/description',
  'https://leetcode.com/problems/search-insert-position/#/description',
  'https://leetcode.com/problems/count-and-say/#/description',
  'https://leetcode.com/problems/maximum-subarray/#/description',
  'https://leetcode.com/problems/spiral-matrix/#/description',
  'https://leetcode.com/problems/length-of-last-word/#/description',
  'https://leetcode.com/problems/sqrtx/#/description',
  'https://leetcode.com/problems/validate-binary-search-tree/',
  'https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/#/description',
];

urls.forEach((url) => {
  request(url, (err, response, body) => {
    var $ = cheerio.load(body);
    var textArr = $('.question-title h3').text().trim().split('. ');
    var no = textArr[0];
    var title = textArr[1];
    var difficulty = $('.question-info li').eq(2).text().split(': ').pop();

    var folderPath = `Algorithms/${title}`;
    var filePath = `${folderPath}/README.md`;

    console.log(no, title, difficulty);

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

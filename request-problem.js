var fs = require('fs');
var request = require('request');
var cheerio = require('cheerio');

var urls = [
  'https://leetcode.com/problems/nth-digit/#/description',
  'https://leetcode.com/problems/queue-reconstruction-by-height/#/description',
  'https://leetcode.com/problems/arithmetic-slices/#/description',
  'https://leetcode.com/problems/third-maximum-number/#/description',
  'https://leetcode.com/problems/number-of-segments-in-a-string/#/description',
  'https://leetcode.com/problems/path-sum-iii/#/description',
  'https://leetcode.com/problems/arranging-coins/#/description',
  'https://leetcode.com/problems/find-all-duplicates-in-an-array/#/description',
  'https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/#/description',
  'https://leetcode.com/problems/delete-node-in-a-bst/#/description',
  'https://leetcode.com/problems/minimum-moves-to-equal-array-elements/#/description',
  'https://leetcode.com/problems/repeated-substring-pattern/#/description',
  'https://leetcode.com/problems/hamming-distance/#/description',
  'https://leetcode.com/problems/first-bad-version/#/description',
  'https://leetcode.com/problems/power-of-four/#/description',
  'https://leetcode.com/problems/reverse-vowels-of-a-string/#/description',
  'https://leetcode.com/problems/valid-perfect-square/#/description',
  'https://leetcode.com/problems/guess-number-higher-or-lower/#/description'
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

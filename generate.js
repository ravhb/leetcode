var fs = require('fs');
var events = require('events');
var proxy = new events.EventEmitter();

var dir = './Algorithms';
var repo_url = 'https://github.com/duteng/leetcode/tree/master/Algorithms/';
var ret = [];

targetDirs = fs.readdir(dir, function(err, files) {
    var count = files.length;
    files.forEach(function(value, index, arr) {
        fs.readFile(dir + '/' + value + '/README.md', {encoding: 'utf8'}, function(err, data) {
            var no = parseInt(data.match(/###### No:`(\d+)`/)[1], 10);
            var difficulty = data.match(/###### Difficulty:`(\w+)`/)[1];
            var title = data.match(/# \[(.*)\]/)[1];
            var link = '[JavaScript](' + repo_url + title.replace(/\s/g, '%20') + ')';
            ret.push({
                no: no,
                title:title,
                difficulty: difficulty,
                link: link
            });
            if(ret.length == count) {
                proxy.emit('readDone');
            }

        });
    });
});

proxy.once('readDone', function() {
    ret.sort(function(a, b) {
        return a.no - b.no;
    });

    var content = [
        'leetcode',
        '========',
        'My JavaScript Solution of [leetcode](http://oj.leetcode.com/problems/)',
        '',
        '',
        '| No | Title | Source Code | Difficulty |',
        '|----| ----- | -------- | ---------- |'
    ].join('\r\n') + '\r\n';

    for(var i = 0; i < ret.length; i++) {
        content += '|' + ret[i].no + '|' + ret[i].title + '|' + ret[i].link + '|' + ret[i].difficulty + '|' + '\r\n';
    }
    fs.writeFile('README.md', content);
});

#!/usr/bin/node

const request = require('request');
const process = require('process');

const filmNumber = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + filmNumber + '?format=json';

request(url, function (error, response, body) {
  if (error || response.statusCode !== 200) return;
  const info = JSON.parse(body);
  info.characters.forEach(character => {
    request(character, (error, response, body) => {
      if (error || response.statusCode !== 200) return;
      const characterData = JSON.parse(body);
      console.log(characterData.name);
    });
  });
});

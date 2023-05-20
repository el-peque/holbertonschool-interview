#!/usr/bin/node

const request = require('request');
const process = require('process');

function getRequest (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error || response.statusCode !== 200) {
        reject(error || new Error(`Request failed with status code ${response.statusCode}`));
      } else {
        resolve(JSON.parse(body));
      }
    });
  });
}

async function getMovieCharacters (filmNumber) {
  const url = 'https://swapi-api.hbtn.io/api/films/' + filmNumber;

  try {
    const movieData = await getRequest(url);
    const characterPromises = movieData.characters.map(characterUrl => getRequest(characterUrl));
    const characterDataList = await Promise.all(characterPromises);

    characterDataList.forEach(characterData => {
      console.log(characterData.name);
    });
  } catch (error) {
    console.error(error.message);
  }
}

getMovieCharacters(process.argv[2]);

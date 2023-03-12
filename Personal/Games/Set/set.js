class Card {
  constructor(color, shape, number, fill) {
    this.color = color
    this.shape = shape
    this.number = number
    this.fill = fill
  }
}

const DECK = buildDeck()
const CLICKED_CARDS = []

function buildGameboard() {
  cardsInPlay = document.createElement('div')
  cardsInPlay.id = 'cards-in-play'
  document.getElementById('main').appendChild(cardsInPlay)
  deckRemaining = document.createElement('div')
  deckRemaining.id = 'deck-remaining'
  document.getElementById('main').appendChild(deckRemaining)

  for (let i = 0; i < 12; i++) {
    let newCard = document.createElement('div')
    newCard.className = 'card'
    newCard.id = 'card-' + (i + 1)
    newCard.addEventListener('click', function () {
      newCard.classList.toggle('clicked')
      if (newCard.classList.contains('clicked')) {
        CLICKED_CARDS.push(newCard)
        if (CLICKED_CARDS.length == 3) {
          for (let i = 2; i >= 0; i--) {
            CLICKED_CARDS[i].classList.toggle('clicked')
            CLICKED_CARDS.splice(i,1)
          }
        }
        console.log(CLICKED_CARDS)
      }
      for (let i = 0; i < CLICKED_CARDS.length; i++) {
        if (!CLICKED_CARDS[i].classList.contains('clicked')) {
          CLICKED_CARDS.splice(i,1)
        }
      }
    })
    document.getElementById('cards-in-play').appendChild(newCard)
  }
  let deckCard = document.createElement('div')
  deckCard.classList.add('deck')
  document.getElementById('deck-remaining').appendChild(deckCard)
}

function buildDeck() {
  let colors = ['red', 'green', 'purple']
  let shapes = ['oval', 'diamond', 'snake']
  let numbers = [1, 2, 3]
  let fills = ['solid', 'stripe', 'empty']

  let deck = []

  for (const i of colors) {
    for (const j of shapes) {
      for (const k of numbers) {
        for (const l of fills) {
          deck.push(new Card(i, j, k, l))
        }
      }
    }
  }
  return deck
}

function playGame() {
  buildGameboard()
  let deck = DECK
  for (let i = 0; i < 12; i++) {
    let currCard = getCard(deck)
    let cardId = '#card-' + (i + 1)
    let gameCard = document.querySelector(cardId)
    for (let i = 1; i <= currCard.number; i++) {
      let symbolDiv = document.createElement('div')
      symbolDiv.id = 'symbol'
      symbolDiv.classList.add(currCard.color)
      symbolDiv.classList.add(currCard.shape)
      symbolDiv.classList.add(currCard.fill)
      symbolDiv.classList.add(('n' + currCard.number + '-' + i))
      gameCard.appendChild(symbolDiv)
    }
  }
  console.log(deck)
}

function getCard(deck) {
  let cardIndex = Math.floor(Math.random() * (DECK.length - 1))
  let returnCard = deck[cardIndex]
  deck.splice(cardIndex, 1)
  return returnCard  
}

playGame()

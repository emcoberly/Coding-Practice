function buildGameboard() {
  const deck = buildDeck()

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
    })
    document.getElementById('cards-in-play').appendChild(newCard)
  }
  let deckCard = document.createElement('div')
  deckCard.classList.add('deck')
  document.getElementById('deck-remaining').appendChild(deckCard)
}

class Card {
  constructor(color, shape, number, fill) {
    this.color = color
    this.shape = shape
    this.number = number
    this.fill = fill
  }
}

function buildDeck() {
  let colors = ['red', 'green', 'purple']
  let shapes = ['pill', 'diamond', 'snake']
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
  let gameOver = false
}

playGame()

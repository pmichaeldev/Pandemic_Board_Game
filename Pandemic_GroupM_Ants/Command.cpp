#include "Command.h"

void DiscardCard::execute()
{
	Card** cards = player->discardCard(index, size);
	for (int i = 0; i < size; i++) {
		if (cards[i]->getType() == "City") {
			delete cards[i];
			cards[i] = nullptr;
		}
		else {
			playerDeck->discard(cards[i]);
		}
	}
}

void DiscardCardAndMove::execute()
{
	Card* card = *player->moveAndDiscard(newLocation, index);
	if (card->getType() == "City") {
		delete card;
		card = nullptr;
	}
	else {
		playerDeck->discard(card);
	}
}

void AddCardToHand::execute()
{
	Card** returnedValue = player->addCard(card);
	if (returnedValue != nullptr) {
		Card* discard = *returnedValue;
		if (discard->getType() == "City") {
			delete discard;
			discard = nullptr;
		}
		else {
			playerDeck->discard(discard);
		}
	}
}

void TransferCard::execute()
{
	Card* card = *fromPlayer->discardCard(&index, 1);
	Card** returnedValue = toPlayer->addCard(card);
	if (returnedValue != nullptr) {
		Card* discardCard = *returnedValue;
		if (discardCard->getType() == "City") {
			delete discardCard;
			discardCard = nullptr;
		}
		else {
			playerDeck->discard(discardCard);
		}
	}
}

void addCardToPocket::execute()
{
	player->addExtraPlannerCard(card);
}

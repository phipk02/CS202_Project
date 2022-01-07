/*SaveState::SaveState(StateStack& stack, Context context)
	: State(stack, context)
	, mOptions()
	, mOptionIndex(0)
	, mNextOptions()
	, mNextOptionsIndex(0)
	, isFinished(false)
{

	sf::Texture& texture = context.textures->get(Textures::Background);
	sf::Font& font = context.fonts->get(Fonts::Main);

	context.window->clear();

	mBackgroundSprite.setTexture(texture);

	mStateName.setFont(font);
	mStateName.setString("SAVE GAME");
	centerOrigin(mStateName);
	mStateName.setCharacterSize(50);
	mStateName.setStyle(sf::Text::Bold);
	mStateName.setPosition(context.window->getView().getSize().x / 2.f, 55.f);

	// A simple menu demonstration
	sf::Text saveOption1;
	saveOption1.setFont(font);
	saveOption1.setString("Slot 1");
	centerOrigin(saveOption1);
	saveOption1.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -45.f));
	mOptions.push_back(saveOption1);

	sf::Text saveOption2;
	saveOption2.setFont(font);
	saveOption2.setString("Slot 2");
	centerOrigin(saveOption2);
	saveOption2.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -15.f));
	mOptions.push_back(saveOption2);

	sf::Text saveOption3;
	saveOption3.setFont(font);
	saveOption3.setString("Slot 3");
	centerOrigin(saveOption3);
	saveOption3.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 15.f));
	mOptions.push_back(saveOption3);

	sf::Text returnOption;
	returnOption.setFont(font);
	returnOption.setString("Return");
	centerOrigin(returnOption);
	returnOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 45.f));
	mOptions.push_back(returnOption);

	finishText.setFont(font);
	finishText.setString("Save successfully!");
	centerOrigin(finishText);
	finishText.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -60.f));

	sf::Text continueOption;
	continueOption.setFont(font);
	continueOption.setString("Continue");
	centerOrigin(continueOption);
	continueOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -15.f));
	mNextOptions.push_back(continueOption);

	sf::Text mainMenuOption;
	mainMenuOption.setFont(font);
	mainMenuOption.setString("Return to main menu");
	centerOrigin(mainMenuOption);
	mainMenuOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 15.f));
	mNextOptions.push_back(mainMenuOption);

	updateOptionText();
	std::cout << "Save\n";
}

void SaveState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);

	if (isFinished) {
		window.draw(finishText);

		FOREACH(const sf::Text & text, mNextOptions)
			window.draw(text);
	}
	else {
		window.draw(mStateName);

		FOREACH(const sf::Text & text, mOptions)
			window.draw(text);
	}
}

bool SaveState::update(sf::Time)
{
	playSound();
	return false;
}

bool SaveState::handleEvent(const sf::Event& event)
{
	// The demonstration menu logic
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (isFinished) {
		if (event.key.code == sf::Keyboard::Up)
		{
			// Decrement and wrap-around
			if (mNextOptionsIndex > 0)
				mNextOptionsIndex--;
			else
				mNextOptionsIndex = mNextOptions.size() - 1;

			updateOptionText();
		}

		else if (event.key.code == sf::Keyboard::Down)
		{
			// Increment and wrap-around
			if (mNextOptionsIndex < mNextOptions.size() - 1)
				mNextOptionsIndex++;
			else
				mNextOptionsIndex = 0;

			updateOptionText();
		}

		else if (event.key.code == sf::Keyboard::Return) {
			if (mNextOptionsIndex == OptionNext::Continue)
				requestStackPop();
			else {
				requestStateClear();
				requestStackPush(States::Menu);
			}
		}
	}

	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == Slot1)
		{
			GameState::save("E:/CS202/Project1/Project1/saveFile/1.bin");
			isFinished = true;
		}
		else if (mOptionIndex == Slot2) {
			GameState::save("E:/CS202/Project1/Project1/saveFile/2.bin");
			isFinished = true;
		}
		else if (mOptionIndex == Slot3) {
			GameState::save("E:/CS202/Project1/Project1/saveFile/3.bin");
			isFinished = true;
		}
		else if (mOptionIndex == Return)
		{
			std::cout << "Save pop\n";
			// The exit option was chosen, by removing itself, the stack will be empty, and the game will know it is time to close.
			requestStackPop();
		}
	}

	else if (event.key.code == sf::Keyboard::Up)
	{
		// Decrement and wrap-around
		if (mOptionIndex > 0)
			mOptionIndex--;
		else
			mOptionIndex = mOptions.size() - 1;

		updateOptionText();
	}

	else if (event.key.code == sf::Keyboard::Down)
	{
		// Increment and wrap-around
		if (mOptionIndex < mOptions.size() - 1)
			mOptionIndex++;
		else
			mOptionIndex = 0;

		updateOptionText();
	}

	return false;
}
*/
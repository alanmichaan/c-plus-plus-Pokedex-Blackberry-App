#include "applicationui.h"
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/DropDown>
#include <bb/cascades/RadioGroup>
#include <bb/cascades/Label>
#include <iostream>
#include "pokemonlist.h"

using namespace bb::cascades;
using std::cerr;
using std::endl;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
        QObject(app), m_pokemonList(0), current_language(9)
{
    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    // root object for the UI
    root = qml->createRootObject<AbstractPane>();

    // Set the handle for the "pokedex" object from QML
    qml->setContextProperty("pokedex", this);

    // Create the "model" to store data about pokemon
    m_pokemonList = new PokemonList(this);
    qml->setContextProperty("pokemon_list", m_pokemonList);

    //set the language menu, will assign current_language to English
    //initiate the dropdown
    //add the proper types to the dropdown
    languageMenu();
    initDropdown();
    Dropdown();

    //refresh the screen
    refreshTypes();

    // Set created root object as the application scene
    app->setScene(root);
}

void ApplicationUI::typeSelected(int type) {

	//the the member_variable current_type equal to the type passed in
	//call the typeChanged() function in pokemonList class
	//refresh
	cerr << "In typeSelected() with " << "type=" << type << endl;
	current_type = type;
	m_pokemonList->typeChanged(current_type);
	refreshTypes();
}

void ApplicationUI::languageSelected(int language) {

	//set the current_language member = to the language passed into the function
	//call the languageChanged function of the pokemonList class
	current_language = language;
	cerr << "In languageSelected() with " << "language=" << current_language << endl;
   	m_pokemonList->languageChanged(current_language);
	Dropdown();
}

void ApplicationUI::Dropdown() {

	// Populate the dropdown list of types
	DropDown *dropDown(0);	// pointer to hold the DropDown UI object
	// Search the root QML object for a control named "pokemon_types"
	dropDown = root->findChild<DropDown *>("pokemon_types");

	// did we succeed in getting a pointer to the drop down UI control?
	if (dropDown) {

		//remove all items in the dropdown
		//then add the proper types of the selected language
		dropDown->removeAll();
		if(current_language == 1){
			for (int i = 0; i < languages_japanese.size(); i ++){
				dropDown->add(Option::create().text(languages_japanese[i]).value(i));
			}
		}
		else if(current_language == 5){
			for (int i = 0; i < languages_french.size(); i ++){
				dropDown->add(Option::create().text(languages_french[i]).value(i));
			}
		}
		else if(current_language == 6){
			for (int i = 0; i < languages_german.size(); i ++){
				dropDown->add(Option::create().text(languages_german[i]).value(i));
			}
		}
		else if(current_language == 7){
			for (int i = 0; i < languages_spanish.size(); i ++){
				dropDown->add(Option::create().text(languages_spanish[i]).value(i));
			}
		}
		else if(current_language == 8){
			for (int i = 0; i < languages_italian.size(); i ++){
				dropDown->add(Option::create().text(languages_italian[i]).value(i));
			}
		}
		else if (current_language == 9 || current_language == 2 ||current_language == 3 ||current_language == 4){
			//start at 1 cause randomly putting variables in index 0
			for (int j = 0; j < languages_english.size(); j++)
				dropDown->add(Option::create().text(languages_english[j]).value(j));
		}
	}
	else cerr << "failed to find pokemon_types " << endl;
}

void ApplicationUI::languageMenu() {
	RadioGroup *radio(0);
	radio = root->findChild<RadioGroup *>("pokedex_languages");

	//adds the languages to the radio buttons
	if (radio) {
		QFile file("app/native/assets/data/language_names.csv");
			if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
				QTextStream in(&file);
				in.readLine();
				while (!in.atEnd()) {
					QStringList languages = in.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive);

					//the default language is japanese, select japanese etc..
					//if the defeault language is english select english etc..
					//add all the other radio buttons
					if (languages[1] == "9"){
						if(current_language == 1 && languages[2] == "Japanese"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else if (current_language == 9 && languages[2] == "English"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else if (current_language == 2 && languages[2] == "Official roomaji"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else if (current_language == 3 && languages[2] == "Korean"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else if (current_language == 4 && languages[2] == "Chinese"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else if (current_language == 5 && languages[2] == "French"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else if (current_language == 6 && languages[2] == "German"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else if (current_language == 7 && languages[2] == "Spanish"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else if (current_language == 8 && languages[2] == "Italian"){
							radio->add(Option::create().text(languages[2]).value(languages[0]).selected(true));
						}
						else
							radio->add(Option::create().text(languages[2]).value(languages[0]));
					}
				}
			}
			//failed to open
			else{
				cerr << "Failed to open types.csv: " << file.error() << endl;
				exit(0);
			}
	}
	else cerr << "failed to find pokedex_languages " << endl;
}

void ApplicationUI::refreshTypes() {
	 Label *status(0);

	    // Search the root QML object for a control named "status"
	    status = root->findChild<Label *>("pokedex_status");

	    // did we succeed in getting a pointer to the Label UI control?
	    if (status) {
	    	// Yes. Now set the text as appropriate
	    	status->setText( QString("Found %1 Pok").arg(m_pokemonList->childCount(QVariantList())) +QChar(0x0E9)+QString("mon") );	    }
	    else {
	    	cerr << "failed to find status " << endl;
	    }
}

void ApplicationUI::initDropdown() {

	//open the file with the different languages
	QFile file("app/native/assets/data/type_names.csv");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

		QTextStream in(&file);
		int counter_i = 0;

		//Add "All Types" to the dropdown
		//add "All Types" in japanese
		QString japanese_all_types = QString::fromLocal8Bit("全てのタイプ");
		languages_english.append("All Types");
		languages_japanese.append(japanese_all_types);
		languages_french.append("All Types");
		languages_german.append("All Types");
		languages_spanish.append("All Types");
		languages_italian.append("All Types");

		while (counter_i < 104) {
			//parse the list
			QStringList types_list = in.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive);

			//append the pokemon types for each language into lists
			if (types_list[1] == "9"){
				languages_english.append(types_list[2]);
			}
			else if (types_list [1] == "1"){
				languages_japanese.append(types_list[2]);
			}
			else if(types_list [1] == "5"){
				languages_french.append(types_list[2]);
			}
			else if(types_list [1] == "6"){
				languages_german.append(types_list[2]);
			}
			else if(types_list [1] == "7"){
				languages_spanish.append(types_list[2]);
			}
			else if(types_list [1] == "8"){
				languages_italian.append(types_list[2]);
			}
			counter_i++;
		}

		//append fairy to the 18th index of each language's "type list"
		//there is no translation for any language.
		languages_japanese.append("Fairy [English]");
		languages_french.append("Fairy [English]");
		languages_german.append("Fairy [English]");
		languages_spanish.append("Fairy [English]");
		languages_italian.append("Fairy [English]");

	}
	else{
		cerr << "Failed to open types.csv: " << file.error() << endl;
		exit(0);
	}
}

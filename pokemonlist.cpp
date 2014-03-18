#include "pokemonlist.h"
using std::endl;
#include <iostream>
#include <bb/cascades/DataModelChangeType>

/*
 * PokemonList is derive from DataModel which provides the base class for the "model"
 * in the model-view-controller pattern used by the ListView UI control
*/

PokemonList::PokemonList(QObject* parent) : bb::cascades::DataModel(parent) {
	//completed_init_function = false;
}

// Return the number of child items contained in a given entry
// Since we only implement a flat list, we must return 0 for any sub item.
int PokemonList::childCount(const QVariantList& indexPath) {

	if (indexPath.empty()){

		//returning the amount of each type of pokemon if filtered or not filtered
		//for example, if the "normal" type is selected, the screen will show the number of
		//pokemon with types "normal"
		if (link_type == 1) 		return type_normal.size()/45;
		else if (link_type == 2)	return type_fighting.size()/45;
		else if (link_type == 3)	return type_flying.size()/45;
		else if (link_type == 4)	return type_poison.size()/45;
		else if (link_type == 5)	return type_ground.size()/45;
		else if (link_type == 6)	return type_rock.size()/45;
		else if (link_type == 7)	return type_bug.size()/45;
		else if (link_type == 8)	return type_ghost.size()/45;
		else if (link_type == 9)	return type_steel.size()/45;
		else if (link_type == 10)	return type_fire.size()/45;
		else if (link_type == 11)	return type_water.size()/45;
		else if (link_type == 12)	return type_grass.size()/45;
		else if (link_type == 13)	return type_electric.size()/45;
		else if (link_type == 14)	return type_psychic.size()/45;
		else if (link_type == 15)	return type_ice.size()/45;
		else if (link_type == 16)	return type_dragon.size()/45;
		else if (link_type == 17)	return type_dark.size()/45;
		else if (link_type == 18) 	return type_fairy.size()/45;
		else 						return	718;
	}
	return 0;
}

// Used for displaying multi-level lists
bool PokemonList::hasChildren(const QVariantList& indexPath) {
	if (indexPath.empty())
		// The root node always has children
		return true;
	else
		return false;
}

QVariant PokemonList::data(const QVariantList& indexPath) {

	//if the init function has not been called
	if (pokemon_list.size() <3590) init();
	int i = indexPath[0].toInt();
	QVariantMap data;

	//the qstring pokemon stores the pokemon name, the number and the types
	QString  pokemon;

	//qstring to store the ability of the pokemon
	QString ability_name;

	//qstring that stores the number and name of the pokemon in the selected language
	QString stats_page_name;

	//stores the type in the appropriate language
	QString type_language;

	//qstring to store all the names of a pokemon of a specific type
	QString type_filter;

	//sets the string "type_filter" equal to the selected type at the appropriate index
	if (link_type == 1) 		type_filter = type_normal[link_language - 1 + i*9];
	else if (link_type == 2)	type_filter = type_fighting[link_language - 1 + i*9];
	else if (link_type == 3)	type_filter = type_flying[link_language - 1 + i*9];
	else if (link_type == 4)	type_filter = type_poison[link_language - 1 + i*9];
	else if (link_type == 5)	type_filter = type_ground[link_language - 1 + i*9];
	else if (link_type == 6)	type_filter = type_rock[link_language - 1 + i*9];
	else if (link_type == 7)	type_filter = type_bug[link_language - 1 + i*9];
	else if (link_type == 8)	type_filter = type_ghost[link_language - 1 + i*9];
	else if (link_type == 9)	type_filter = type_steel[link_language - 1 + i*9];
	else if (link_type == 10)	type_filter = type_fire[link_language - 1 + i*9];
	else if (link_type == 11)	type_filter = type_water[link_language - 1 + i*9];
	else if (link_type == 12)	type_filter = type_grass[link_language - 1 + i*9];
	else if (link_type == 13)	type_filter = type_electric[link_language - 1 + i*9];
	else if (link_type == 14)	type_filter = type_psychic[link_language - 1 + i*9];
	else if (link_type == 15)	type_filter = type_ice[link_language - 1 + i*9];
	else if (link_type == 16)	type_filter = type_dragon[link_language - 1 + i*9];
	else if (link_type == 17)	type_filter = type_dark[link_language - 1 + i*9];
	else if (link_type == 18) 	type_filter = type_fairy[link_language - 1 + i*9];

	//intantiates the name of the pokemon on the main page, the name on the stats page,
	// and the ability; all in the proper language,
	//if no language was available the proper QString is displayed in English
	if (link_language == 9){
		pokemon = pokemon_list[i];//pokemon_list[1]  Get the name of pokemon for this index
		ability_name = total_ability[i];
		stats_page_name = name_number[i];
		type_language = number_type[i];
	}
	else if (link_language == 1){
		pokemon = pokemon_list_japanese[i];
		ability_name = total_ability_japanese[i];
		stats_page_name = name_number_japanese[i];
		type_language = number_type_japanese[i];
	}
	else if (link_language == 2){
		pokemon = pokemon_list_roomaji[i];
		ability_name = total_ability[i];
		stats_page_name = name_number_roomaji[i];
		type_language = number_type[i];
	}
	else if (link_language == 3){
		pokemon = pokemon_list_korean[i];
		ability_name = total_ability[i];
		stats_page_name = name_number_korean[i];
		type_language = number_type[i];
	}
	else if (link_language == 4){
		pokemon = pokemon_list_chinese[i];
		ability_name = total_ability[i];
		stats_page_name = name_number_chinese[i];
		type_language = number_type[i];
	}
	else if (link_language == 5){
		pokemon = pokemon_list_french[i];
		ability_name = total_ability_french[i];
		stats_page_name = name_number_french[i];
		type_language = number_type_french[i];
	}
	else if (link_language == 6){
		pokemon = pokemon_list_german[i];
		ability_name = total_ability_german[i];
		stats_page_name = name_number_german[i];
		type_language = number_type_german[i];
	}
	else if (link_language == 7){
		pokemon = pokemon_list_spanish[i];
		ability_name = total_ability_spanish[i];
		stats_page_name = name_number[i];
		type_language = number_type_german[i];
	}
	else if (link_language == 8){
		pokemon = pokemon_list_italian[i];
		ability_name = total_ability_italian[i];
		stats_page_name = name_number[i];
		type_language = number_type_italian[i];
	}

	//if a type is selected, filter the pokemon list, else show the entire list
	if (link_type == 0){
		data["aaname"] = pokemon;
	}
	else data["aaname"] = type_filter;

	//data["real_name"] = name_number[i];

	//displays the information on the stats page
	data["bname"] = stats_page_name;

	data["weight"] = weight[i+1];
	data ["height"] = height[i+1];
	data["hit_points"] = hit_points[i];
	data["attack"] = attack[i];
	data["defence"] = defence[i];
	data["special_attack"] = special_attack[i];
	data["special_defence"] = special_defence[i];
	data["speed"] = speed[i];
	data["total_stat_points"] = QString::number(hit_points[i].toInt() + attack[i].toInt() + defence[i].toInt() + special_attack[i].toInt() + special_defence[i].toInt() + speed[i].toInt());
	data["type"] = type_language;
	data["ability"] = ability_name;
	data["description"] = description[i];
	return data;
}

void PokemonList::init() {

		//adding the type names to lists
		QFile file("app/native/assets/data/type_names.csv");
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in(&file);
			type_names.append("null");
			type_names_japanese.append("null");
			type_names_french.append("null");
			type_names_german.append("null");
			type_names_spanish.append("null");
			type_names_italian.append("null");

			while (!in.atEnd()) {
				QStringList type_list = in.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive);

				//if the type name is in english
				//add the type name to the english list
				//"else-ifs" add the type name in the other 8 languages
				//since none of the languages have type number 18 = "Fairy",
				//it is appended to the list once the list has reached 17 elements
				//languages 2,3,4 have the type names all in english so a list is not created for them
				if (type_list[1] == "9" && type_list[2] != "???"){
					type_names.append(type_list[2]);
				}
				else if (type_list[1] == "1" && type_list[2] != "???"){
					type_names_japanese.append(type_list[2]);
					if (type_names_japanese.size() == 18) type_names_japanese.append("Fairy");
				}
				else if (type_list[1] == "5" && type_list[2] != "???"){
					type_names_french.append(type_list[2]);
					if (type_names_french.size() == 18) type_names_french.append("Fairy");
				}
				else if (type_list[1] == "6" && type_list[2] != "???"){
					type_names_german.append(type_list[2]);
					if (type_names_german.size() == 18) type_names_german.append("Fairy");
				}
				else if (type_list[1] == "7" && type_list[2] != "???"){
					type_names_spanish.append(type_list[2]);
					if (type_names_spanish.size() == 18) type_names_spanish.append("Fairy");
				}
				else if (type_list[1] == "8" && type_list[2] != "???"){
					type_names_italian.append(type_list[2]);
					if (type_names_italian.size() == 18) type_names_italian.append("Fairy");
				}
			}
		}
		else{
			std::cerr << "Failed to open type_names.csv: " << file.error() << std::endl;
			exit(0);
		}


		//adding the specific pokmons' type to a list
		QFile file1("app/native/assets/data/pokemon_types.csv");

		//the list "pokemon_particular_types" adds the type number that a pokemon has
		//so index zero of the "pokemon_particular_types" list will hold the type number of the pokemon
		//index one will store either the number one, or the number two,
		//since some pokemon has 2 types we must add this -^ index above as a reference
		if (file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in1(&file1);
			while (!in1.atEnd()) {
				QStringList type_id = in1.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive);
				if (type_id[2] != "slot"){
					pokemon_particular_types.append(type_id[2]);
					pokemon_particular_types.append(type_id[1]);
				}
			}
		}
		else
			std::cerr << "Failed to open pokemon_types.csv: " << file1.error() << std::endl;



		QFile file2("app/native/assets/data/pokemon_species_names.csv");
		if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {

			QTextStream in2(&file2);

			//i and j are two counters that will access indexes in different lists
			int j = 0;
			int i = 1;

			//if there are two types the bool "two_types" will return true, else, false.
			bool two_types = true;

			//this QString will represent whether the number of the pokemon
			//either #, or #0, or #00 depending on the number's size
			QString number_size;
			while (!in2.atEnd()) {

				//assigning a state to "two_types"
				if (pokemon_particular_types[j] == "1" && pokemon_particular_types[j + 2] == "2"){
					two_types = true;
				}
				else two_types = false;

				QStringList poke_list = in2.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive); // Read a line as a QString

				//sets a string according to the size of the number
				if (poke_list[0].toInt() < 10)			number_size = "#00";
				else if (poke_list[0].toInt() < 100)	number_size = "#0";
				else 									number_size = "#";

				//exceptions
				//adding english pokemon to the japanese, german and french lists
				//since there are no translations
				if (i> 4083 && poke_list[1] == "9"){
					if(two_types){
						pokemon_list_japanese.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names_japanese[pokemon_particular_types[j+1].toInt()] + "," + type_names_japanese[pokemon_particular_types[j+3].toInt()] + "]" + " [English]");
						pokemon_list_german.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names_german[pokemon_particular_types[j+1].toInt()] + "," + type_names_german[pokemon_particular_types[j+3].toInt()] + "]" + " [English]");
						pokemon_list_french.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names_french[pokemon_particular_types[j+1].toInt()] + "," + type_names_french[pokemon_particular_types[j+3].toInt()] + "]" + " [English]");
					}
					else
					{
						pokemon_list_japanese.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names_japanese[pokemon_particular_types[j+1].toInt()] + "]" + " [English]");
						pokemon_list_german.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names_german[pokemon_particular_types[j+1].toInt()] + "]" + " [English]");
						pokemon_list_french.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names_french[pokemon_particular_types[j+1].toInt()] + "]" + " [English]");
					}
				}
				//adding english pokemon to the chinese list
				if ((i== 3456 || i ==3465 || i == 3469 || i == 3478 || i == 3482 || (i >=3491 && i<=3523 ) || (i >= 3532 && i<=3920) || (i>=3929 && i <= 4053)|| i>=4067) && poke_list[1] == "9"){
					if(two_types)	pokemon_list_chinese.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "," + type_names[pokemon_particular_types[j+3].toInt()] + "]" + " [English]");
					else 			pokemon_list_chinese.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "]" + " [English]");

				}
				//adding english pokemon to the korean list and roomaji list
				if (i> 3454 && poke_list[1] == "9"){
					if(two_types){
						pokemon_list_korean.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "," + type_names[pokemon_particular_types[j+3].toInt()] + "]" + " [English]");
						pokemon_list_roomaji.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "," + type_names[pokemon_particular_types[j+3].toInt()] + "]" + " [English]");
					}
					else {
						pokemon_list_korean.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "]" + " [English]");
						pokemon_list_roomaji.append("#" + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "]" + " [English]");
					}
				}
				i++;

				//instantiating all the pokemon in different languges
				//each langugae has its pokemon names in different list
				//will have to add the pokemon name in english and the type in either english, spanish or italian
				//the list "name_number" will just store the name and number of the pokemon with no types.
				//this is for the stats page -^
				//code is repetitive until line 411, same process for every list
				if (poke_list[1] == "9"){
					//if has 2 types
					if(two_types){
						pokemon_list.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "," + type_names[pokemon_particular_types[j+3].toInt()] + "]"); //
						pokemon_list_spanish.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_spanish[pokemon_particular_types[j+1].toInt()] + "," + type_names_spanish[pokemon_particular_types[j+3].toInt()] + "]" + " [English]");
						pokemon_list_italian.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_italian[pokemon_particular_types[j+1].toInt()] + "," + type_names_italian[pokemon_particular_types[j+3].toInt()] + "]"+ " [English]");
						number_type.append(type_names[pokemon_particular_types[j+1].toInt()] + "," + type_names[pokemon_particular_types[j+3].toInt()]);
						number_type_spanish.append(type_names_spanish[pokemon_particular_types[j+1].toInt()] + "," + type_names_spanish[pokemon_particular_types[j+3].toInt()] + " [English]");
						number_type_italian.append(type_names_german[pokemon_particular_types[j+1].toInt()] + "," + type_names_german[pokemon_particular_types[j+3].toInt()] + " [English]");
						j = j + 4;
					}
					//has one type
					else  {
						pokemon_list.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "]"); //
						pokemon_list_spanish.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_spanish[pokemon_particular_types[j+1].toInt()] + "]" + " [English]");
						pokemon_list_italian.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_italian[pokemon_particular_types[j+1].toInt()] + "]" + " [English]");
						number_type.append(type_names[pokemon_particular_types[j+1].toInt()]);
						number_type_spanish.append(type_names_spanish[pokemon_particular_types[j+1].toInt()] + " [English]");
						number_type_italian.append(type_names_german[pokemon_particular_types[j+1].toInt()] + " [English]");
						j = j + 2;
					}
					name_number.append(number_size + poke_list[0] + " " + poke_list[2]);
				}
				else if (poke_list[1] == "1"){
					if(two_types){
						number_type_japanese.append(type_names_japanese[pokemon_particular_types[j+1].toInt()] + "," + type_names_japanese[pokemon_particular_types[j+3].toInt()]);
						pokemon_list_japanese.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_japanese[pokemon_particular_types[j+1].toInt()] + "," + type_names_japanese[pokemon_particular_types[j+3].toInt()] + "]");
					}
					else {
						number_type_japanese.append(type_names_japanese[pokemon_particular_types[j+1].toInt()]);
						pokemon_list_japanese.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_japanese[pokemon_particular_types[j+1].toInt()] + "]");
					}
					name_number_japanese.append(number_size + poke_list[0] + " " + poke_list[2]);
				}
				else if (poke_list[1] == "2"){ //add the pokemon names in roomaji but the types in english
					if(two_types)	pokemon_list_roomaji.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "," + type_names[pokemon_particular_types[j+3].toInt()] + "]");
					else  			pokemon_list_roomaji.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "]");
					name_number_roomaji.append(number_size + poke_list[0] + " " + poke_list[2]);
				}
				else if (poke_list[1] == "3"){ //add the pokemon names in korean but the types in english
					if(two_types) 	pokemon_list_korean.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "," + type_names[pokemon_particular_types[j+3].toInt()] + "]");
					else 			pokemon_list_korean.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "]");
					name_number_korean.append(number_size + poke_list[0] + " " + poke_list[2]);

				}
				else if (poke_list[1] == "4"){//names in chinese, types in english
					if(two_types) 	pokemon_list_chinese.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "," + type_names[pokemon_particular_types[j+3].toInt()] + "]");
					else 			pokemon_list_chinese.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names[pokemon_particular_types[j+1].toInt()] + "]");
					name_number_chinese.append(number_size + poke_list[0] + " " + poke_list[2]);

				}
				else if (poke_list[1] == "5"){
					if(two_types){
						number_type_french.append(type_names_french[pokemon_particular_types[j+1].toInt()] + "," + type_names_french[pokemon_particular_types[j+3].toInt()]);
						pokemon_list_french.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_french[pokemon_particular_types[j+1].toInt()] + "," + type_names_french[pokemon_particular_types[j+3].toInt()] + "]");
					}
					else{
						number_type_french.append(type_names_french[pokemon_particular_types[j+1].toInt()]);
						pokemon_list_french.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_french[pokemon_particular_types[j+1].toInt()] + "]");
					}
					name_number_french.append(number_size + poke_list[0] + " " + poke_list[2]);
				}
				else if (poke_list[1] == "6"){
					if(two_types){
						number_type_german.append(type_names_german[pokemon_particular_types[j+1].toInt()] + "," + type_names_german[pokemon_particular_types[j+3].toInt()]);
						pokemon_list_german.append(number_size + poke_list[0] + " " + poke_list[2] + " [" + type_names_german[pokemon_particular_types[j+1].toInt()] + "," + type_names_german[pokemon_particular_types[j+3].toInt()] + "]");
					}
					else{
						number_type_german.append(type_names_german[pokemon_particular_types[j+1].toInt()]);
						pokemon_list_german.append(number_size + poke_list[0] + " " + poke_list[2]+ " [" + type_names_german[pokemon_particular_types[j+1].toInt()] + "]");
					}
					name_number_german.append(number_size + poke_list[0] + " " + poke_list[2]);
				}
			}
		}
		else{
			std::cerr << "Failed to open pokemon_species_names.csv: " << file2.error() << std::endl;
			exit(0);
		}

		//adding the heights and weights of pokemon onto individual lists
		QFile file5("app/native/assets/data/pokemon.csv");
		if (file5.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in5(&file5);
			while (!in5.atEnd()) {
				QStringList stats = in5.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive);
				weight.append(QString::number(stats[4].toDouble()/10));
				height.append(QString::number(stats[3].toDouble()/10));
			}
		}
		else{
			std::cerr << "Failed to open pokemon.csv: " << file5.error() << std::endl;
			exit(0);
		}

		//initializing lists for the hit points, attack, defence, special_attack, special_defence, speed
		QFile file6("app/native/assets/data/pokemon_stats.csv");
		if (file6.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in6(&file6);
			while (!in6.atEnd()) {
				QStringList stats2 = in6.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive);
				if (stats2[1] == "1") 		hit_points.append(stats2[2]);
				else if (stats2[1] == "2")	attack.append(stats2[2]);
				else if (stats2[1] == "3")	defence.append(stats2[2]);
				else if (stats2[1] == "4")	special_attack.append(stats2[2]);
				else if (stats2[1] == "5")	special_defence.append(stats2[2]);
				else if (stats2[1] == "6")	speed.append(stats2[2]);
			}
		}
		else{
			std::cerr << "Failed to open pokemon_stats.csv: " << file6.error() << std::endl;
			exit(0);
		}

		//adding the abilities to lists which differ by language
		QFile file7("app/native/assets/data/ability_names.csv");
		if (file7.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in7(&file7);

			//appending null to the first index of each list so that ability1 will be in index 1 etc..
			ability_japanese.append("null");
			ability_german.append("null");
			ability_spanish.append("null");
			ability_italian.append("null");
			ability_french.append("null");
			ability.append("null");
			int countxx = 1;

			while (!in7.atEnd()) {
				QStringList ability1 = in7.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive);

				//adding english abilities to other languages that dont have the translation
				if (countxx > 984 && countxx <1058 && ability1[1] == "9"){
					ability_german.append(ability1[2]);
					ability_spanish.append(ability1[2]);
					ability_japanese.append(ability1[2]);
				}
				if (ability1[1] == "1") 		ability_japanese.append(ability1[2]);
				else if (ability1[1] == "5")	ability_french.append(ability1[2]);
				else if (ability1[1] == "6")	ability_german.append(ability1[2]);
				else if (ability1[1] == "7")	ability_spanish.append(ability1[2]);
				else if (ability1[1] == "8")	ability_italian.append(ability1[2]);
				else if (ability1[1] == "9")	ability.append(ability1[2]);
				countxx++;
			}
		}
		else{
			std::cerr << "Failed to open ability_names.csv: " << file7.error() << std::endl;
			exit(0);
		}

		//adding a pokemons particular ability ID to a list
		//a pokemon may have up to 3 abilities so i appended two more indexes of the
		//"pokemon_abilities" file for reference
		QFile file8("app/native/assets/data/pokemon_abilities.csv");
		if (file8.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in8(&file8);
			while (!in8.atEnd()) {
				QStringList ability2 = in8.readLine().split(",", QString::KeepEmptyParts, Qt::CaseInsensitive);
				if (ability2[0] != "pokemon_id" && ability2[2] != "ability_id" && ability2[3] != "slot" ){
					pokemon_ability.append(ability2[0]);
					pokemon_ability.append(ability2[1]);
					pokemon_ability.append(ability2[3]);
				}
			}
		}
		else{
			std::cerr << "Failed to open pokemon_abilities.csv: " << file8.error() << std::endl;
			exit(0);
		}

		//adding the descriptions and vesions of the pokemon to lists
		QFile file9("app/native/assets/data/pokemon_species_flavor_text.csv");
		if (file9.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in9(&file9);
			QString title = in9.readLine();
			QStringList full_description = in9.readAll().split("\"");
			int line_zero_int = 1;
			int counterr = 0;

			//adding the description and the version of the pokemon accordingly
			//comma[1] stores the version number, full_description[counter + 1] stores the description
			while (line_zero_int < 719){
				QStringList comma = full_description[counterr].split(",");
				if (line_zero_int == comma[0].toInt()){
					if (comma[1].toInt() == 1 || comma[1].toInt() ==2){
						description.append(full_description[counterr + 1] + " Version: red-blue.");
					}
					else if (comma[1].toInt() == 3){
						description.append(full_description[counterr + 1] + " Version: yellow.");
					}
					else if (comma[1].toInt() == 4 || comma[1].toInt() == 5){
						description.append(full_description[counterr + 1] + " Version: gold-silver.");
					}
					else if (comma[1].toInt() == 6){
						description.append(full_description[counterr + 1] + " Version: ruby-sapphire.");
					}
					else if (comma[1].toInt() == 7 || comma[1].toInt() == 8){
						description.append(full_description[counterr + 1] + " Version: Crystal.");
					}
					else if (comma[1].toInt() == 9){
						description.append(full_description[counterr + 1] + " Version: emerald.");
					}
					else if (comma[1].toInt() == 10 || comma[1].toInt() == 11){
						description.append(full_description[counterr + 1] + " Version: firered-leafgreen.");
					}
					else if (comma[1].toInt() == 12 || comma[1].toInt() == 13){
						description.append(full_description[counterr + 1] + " Version: diamond-pearl.");
					}
					else if (comma[1].toInt() == 14){
						description.append(full_description[counterr + 1] + " Version: Platinum.");
					}
					else if (comma[1].toInt() == 15 || comma[1].toInt() == 16){
						description.append(full_description[counterr + 1] + " Version: heartgold-soulsilver.");
					}
					else if (comma[1].toInt() == 17 || comma[1].toInt() == 18){
						description.append(full_description[counterr + 1] + " Version: black-white.");
					}
					else if (comma[1].toInt() == 19){
						description.append(full_description[counterr + 1] + " Version: colosseum.");
					}
					else if (comma[1].toInt() == 20){
						description.append(full_description[counterr + 1] + " Version: XD.");
					}
					else if (comma[1].toInt() == 21 || comma[1].toInt() == 22){
						description.append(full_description[counterr + 1] + " Version: black-2-white-2.");
					}
					else if (comma[1].toInt() == 23 || comma[1].toInt() == 24){
						description.append(full_description[counterr + 1] + " Version: x-y.");
					}
					line_zero_int++;
				}
				counterr = counterr + 2;
			}
		}
		else{
			std::cerr << "Failed to open pokemon_species_flavor_text.csv: " << file9.error() << std::endl;
			exit(0);
		}

		//call this function to link the ability index with the ability names
		//and also to create lists of all the types for the stats page
		abilityTypesStatsPage();

}

void PokemonList::languageChanged(int new_language) {
	link_language = new_language;
	emit itemsChanged( bb::cascades::DataModelChangeType::Init);
}

void PokemonList::abilityTypesStatsPage() {

	int count2 = 0;
	int indexx = 0;

	//abilities for stats page
	//appending abilities to the proper list
	while(count2 < 718){

		//if the pokemon has 2 abilities
		//else if the pokemon has three abilities
		//else the pokemon has one abiliity
		if (pokemon_ability[indexx + 2] == "1" && pokemon_ability[indexx + 5] == "3"){
			total_ability.append(ability[pokemon_ability[indexx + 1].toInt()] + ", " + ability[pokemon_ability[indexx + 4].toInt()]);
			total_ability_japanese.append(ability_japanese[pokemon_ability[indexx + 1].toInt()] + ", " + ability_japanese[pokemon_ability[indexx + 4].toInt()]);
			total_ability_french.append(ability_french[pokemon_ability[indexx + 1].toInt()] + ", " + ability_french[pokemon_ability[indexx + 4].toInt()]);
			total_ability_german.append(ability_german[pokemon_ability[indexx + 1].toInt()] + ", " + ability_german[pokemon_ability[indexx + 4].toInt()]);
			total_ability_spanish.append(ability_spanish[pokemon_ability[indexx + 1].toInt()] + ", " + ability_spanish[pokemon_ability[indexx + 4].toInt()]);
			total_ability_italian.append(ability_italian[pokemon_ability[indexx + 1].toInt()] + ", " + ability_italian[pokemon_ability[indexx + 4].toInt()]);
			indexx = indexx + 6;
		}
		else if (pokemon_ability[indexx + 2] == "1" && pokemon_ability[indexx + 5] == "2" && pokemon_ability[indexx + 8] == "3"){
			total_ability.append(ability[pokemon_ability[indexx + 1].toInt()] + ", " + ability[pokemon_ability[indexx + 4].toInt()] + ", " + ability[pokemon_ability[indexx + 7].toInt()]);
			total_ability_japanese.append(ability_japanese[pokemon_ability[indexx + 1].toInt()] + ", " + ability_japanese[pokemon_ability[indexx + 4].toInt()] + ", " + ability_japanese[pokemon_ability[indexx + 7].toInt()]);
			total_ability_french.append(ability_french[pokemon_ability[indexx + 1].toInt()] + ", " + ability_french[pokemon_ability[indexx + 4].toInt()] + ", " + ability_french[pokemon_ability[indexx + 7].toInt()]);
			total_ability_german.append(ability_german[pokemon_ability[indexx + 1].toInt()] + ", " + ability_german[pokemon_ability[indexx + 4].toInt()] + ", " + ability_german[pokemon_ability[indexx + 7].toInt()]);
			total_ability_spanish.append(ability_spanish[pokemon_ability[indexx + 1].toInt()] + ", " + ability_spanish[pokemon_ability[indexx + 4].toInt()] + ", " + ability_spanish[pokemon_ability[indexx + 7].toInt()]);
			total_ability_italian.append(ability_spanish[pokemon_ability[indexx + 1].toInt()] + ", " + ability_italian[pokemon_ability[indexx + 4].toInt()] + ", " + ability_italian[pokemon_ability[indexx + 7].toInt()]);
			indexx = indexx + 9;
		}
		else if (pokemon_ability[indexx + 2] == "1" && pokemon_ability[indexx + 5] != "2" && pokemon_ability[indexx + 8] != "3"){
			total_ability.append(ability[pokemon_ability[indexx + 1].toInt()]);
			total_ability_japanese.append(ability_japanese[pokemon_ability[indexx + 1].toInt()]);
			total_ability_french.append(ability_french[pokemon_ability[indexx + 1].toInt()]);
			total_ability_german.append(ability_german[pokemon_ability[indexx + 1].toInt()]);
			total_ability_spanish.append(ability_spanish[pokemon_ability[indexx + 1].toInt()]);
			total_ability_italian.append(ability_spanish[pokemon_ability[indexx + 1].toInt()]);
			indexx = indexx + 3;
		}
		count2++;
	}


	//types for stats page
	//traversing the list of all pokemon
	//for example if the list contains "Fire" add the particular pokemon
	//to the type_fire list in all languages
	//process is the same up to line 811
	for (int i = 0; i < 718; i++){
		if (pokemon_list[i].contains("Fire")){
			type_fire.append(pokemon_list_japanese[i]);
			type_fire.append(pokemon_list_roomaji[i]);
			type_fire.append(pokemon_list_korean[i]);
			type_fire.append(pokemon_list_chinese[i]);
			type_fire.append(pokemon_list_french[i]);
			type_fire.append(pokemon_list_german[i]);
			type_fire.append(pokemon_list_spanish[i]);
			type_fire.append(pokemon_list_italian[i]);
			type_fire.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Normal")){
			type_normal.append(pokemon_list_japanese[i]);
			type_normal.append(pokemon_list_roomaji[i]);
			type_normal.append(pokemon_list_korean[i]);
			type_normal.append(pokemon_list_chinese[i]);
			type_normal.append(pokemon_list_french[i]);
			type_normal.append(pokemon_list_german[i]);
			type_normal.append(pokemon_list_spanish[i]);
			type_normal.append(pokemon_list_italian[i]);
			type_normal.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Fighting")){
			type_fighting.append(pokemon_list_japanese[i]);
			type_fighting.append(pokemon_list_roomaji[i]);
			type_fighting.append(pokemon_list_korean[i]);
			type_fighting.append(pokemon_list_chinese[i]);
			type_fighting.append(pokemon_list_french[i]);
			type_fighting.append(pokemon_list_german[i]);
			type_fighting.append(pokemon_list_spanish[i]);
			type_fighting.append(pokemon_list_italian[i]);
			type_fighting.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Flying")){
			type_flying.append(pokemon_list_japanese[i]);
			type_flying.append(pokemon_list_roomaji[i]);
			type_flying.append(pokemon_list_korean[i]);
			type_flying.append(pokemon_list_chinese[i]);
			type_flying.append(pokemon_list_french[i]);
			type_flying.append(pokemon_list_german[i]);
			type_flying.append(pokemon_list_spanish[i]);
			type_flying.append(pokemon_list_italian[i]);
			type_flying.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Poison")){
			type_poison.append(pokemon_list_japanese[i]);
			type_poison.append(pokemon_list_roomaji[i]);
			type_poison.append(pokemon_list_korean[i]);
			type_poison.append(pokemon_list_chinese[i]);
			type_poison.append(pokemon_list_french[i]);
			type_poison.append(pokemon_list_german[i]);
			type_poison.append(pokemon_list_spanish[i]);
			type_poison.append(pokemon_list_italian[i]);
			type_poison.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Ground")){
			type_ground.append(pokemon_list_japanese[i]);
			type_ground.append(pokemon_list_roomaji[i]);
			type_ground.append(pokemon_list_korean[i]);
			type_ground.append(pokemon_list_chinese[i]);
			type_ground.append(pokemon_list_french[i]);
			type_ground.append(pokemon_list_german[i]);
			type_ground.append(pokemon_list_spanish[i]);
			type_ground.append(pokemon_list_italian[i]);
			type_ground.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Rock")){
			type_rock.append(pokemon_list_japanese[i]);
			type_rock.append(pokemon_list_roomaji[i]);
			type_rock.append(pokemon_list_korean[i]);
			type_rock.append(pokemon_list_chinese[i]);
			type_rock.append(pokemon_list_french[i]);
			type_rock.append(pokemon_list_german[i]);
			type_rock.append(pokemon_list_spanish[i]);
			type_rock.append(pokemon_list_italian[i]);
			type_rock.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Bug")){
			type_bug.append(pokemon_list_japanese[i]);
			type_bug.append(pokemon_list_roomaji[i]);
			type_bug.append(pokemon_list_korean[i]);
			type_bug.append(pokemon_list_chinese[i]);
			type_bug.append(pokemon_list_french[i]);
			type_bug.append(pokemon_list_german[i]);
			type_bug.append(pokemon_list_spanish[i]);
			type_bug.append(pokemon_list_italian[i]);
			type_bug.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Ghost")){
			type_ghost.append(pokemon_list_japanese[i]);
			type_ghost.append(pokemon_list_roomaji[i]);
			type_ghost.append(pokemon_list_korean[i]);
			type_ghost.append(pokemon_list_chinese[i]);
			type_ghost.append(pokemon_list_french[i]);
			type_ghost.append(pokemon_list_german[i]);
			type_ghost.append(pokemon_list_spanish[i]);
			type_ghost.append(pokemon_list_italian[i]);
			type_ghost.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Water")){
			type_water.append(pokemon_list_japanese[i]);
			type_water.append(pokemon_list_roomaji[i]);
			type_water.append(pokemon_list_korean[i]);
			type_water.append(pokemon_list_chinese[i]);
			type_water.append(pokemon_list_french[i]);
			type_water.append(pokemon_list_german[i]);
			type_water.append(pokemon_list_spanish[i]);
			type_water.append(pokemon_list_italian[i]);
			type_water.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Grass")){
			type_grass.append(pokemon_list_japanese[i]);
			type_grass.append(pokemon_list_roomaji[i]);
			type_grass.append(pokemon_list_korean[i]);
			type_grass.append(pokemon_list_chinese[i]);
			type_grass.append(pokemon_list_french[i]);
			type_grass.append(pokemon_list_german[i]);
			type_grass.append(pokemon_list_spanish[i]);
			type_grass.append(pokemon_list_italian[i]);
			type_grass.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Electric")){
			type_electric.append(pokemon_list_japanese[i]);
			type_electric.append(pokemon_list_roomaji[i]);
			type_electric.append(pokemon_list_korean[i]);
			type_electric.append(pokemon_list_chinese[i]);
			type_electric.append(pokemon_list_french[i]);
			type_electric.append(pokemon_list_german[i]);
			type_electric.append(pokemon_list_spanish[i]);
			type_electric.append(pokemon_list_italian[i]);
			type_electric.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Ice")){
			type_ice.append(pokemon_list_japanese[i]);
			type_ice.append(pokemon_list_roomaji[i]);
			type_ice.append(pokemon_list_korean[i]);
			type_ice.append(pokemon_list_chinese[i]);
			type_ice.append(pokemon_list_french[i]);
			type_ice.append(pokemon_list_german[i]);
			type_ice.append(pokemon_list_spanish[i]);
			type_ice.append(pokemon_list_italian[i]);
			type_ice.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Dragon")){
			type_dragon.append(pokemon_list_japanese[i]);
			type_dragon.append(pokemon_list_roomaji[i]);
			type_dragon.append(pokemon_list_korean[i]);
			type_dragon.append(pokemon_list_chinese[i]);
			type_dragon.append(pokemon_list_french[i]);
			type_dragon.append(pokemon_list_german[i]);
			type_dragon.append(pokemon_list_spanish[i]);
			type_dragon.append(pokemon_list_italian[i]);
			type_dragon.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Dark")){
			type_dark.append(pokemon_list_japanese[i]);
			type_dark.append(pokemon_list_roomaji[i]);
			type_dark.append(pokemon_list_korean[i]);
			type_dark.append(pokemon_list_chinese[i]);
			type_dark.append(pokemon_list_french[i]);
			type_dark.append(pokemon_list_german[i]);
			type_dark.append(pokemon_list_spanish[i]);
			type_dark.append(pokemon_list_italian[i]);
			type_dark.append(pokemon_list[i]);
		}
		if (pokemon_list[i].contains("Fairy")){
			type_fairy.append(pokemon_list_japanese[i]);
			type_fairy.append(pokemon_list_roomaji[i]);
			type_fairy.append(pokemon_list_korean[i]);
			type_fairy.append(pokemon_list_chinese[i]);
			type_fairy.append(pokemon_list_french[i]);
			type_fairy.append(pokemon_list_german[i]);
			type_fairy.append(pokemon_list_spanish[i]);
			type_fairy.append(pokemon_list_italian[i]);
			type_fairy.append(pokemon_list[i]);
		}
	}
}

//if the type is changed set the link_type variable equal to the type number
void PokemonList::typeChanged(int new_type) {
	link_type = new_type;
	emit itemsChanged( bb::cascades::DataModelChangeType::Init);
}



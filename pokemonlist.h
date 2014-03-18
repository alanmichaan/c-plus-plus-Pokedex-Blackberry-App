#ifndef POKEMONLIST_H_
#define POKEMONLIST_H_

#include <bb/cascades/DataModel>

class PokemonList: public bb::cascades::DataModel {
	Q_OBJECT
public:
	PokemonList(QObject *parent = 0);

	bool completed_init_function;

	//name stored in proper index. ex. if type 12 is poison then will be in index 12
	QStringList type_names;
	QStringList type_names_japanese;
	QStringList type_names_french;
	QStringList type_names_german;
	QStringList type_names_spanish;
	QStringList type_names_italian;

	//stores the type number of each pokemon
	QStringList pokemon_particular_types;

	//the final list for the main page
	//eg. #001 Bulbasaur [type1, type2]
	QStringList pokemon_list;
	QStringList pokemon_list_japanese;
	QStringList pokemon_list_roomaji;
	QStringList pokemon_list_korean;
	QStringList pokemon_list_chinese;
	QStringList pokemon_list_french;
	QStringList pokemon_list_german;
	QStringList pokemon_list_italian;
	QStringList pokemon_list_spanish;

	//the name for the stats page
	//eg. #001 Bulbasaur
	QStringList name_number;
	QStringList name_number_japanese;
	QStringList name_number_roomaji;
	QStringList name_number_korean;
	QStringList name_number_chinese;
	QStringList name_number_french;
	QStringList name_number_german;

	//store just the types of each pokemon
	QStringList number_type;
	QStringList number_type_japanese;
	QStringList number_type_french;
	QStringList number_type_german;
	QStringList number_type_spanish;
	QStringList number_type_italian;
	QStringList number_type_chinese;

	//store all the stats
	QStringList height;
	QStringList weight;
	QStringList hit_points;
	QStringList attack;
	QStringList defence;
	QStringList special_attack;
	QStringList special_defence;
	QStringList speed;

	//lists for the abilities ID's
	QStringList ability_japanese;
	QStringList ability_french;
	QStringList ability_spanish;
	QStringList ability_italian;
	QStringList ability_german;
	QStringList ability;

	//lists with the ability name
	QStringList total_ability_japanese;
	QStringList total_ability_french;
	QStringList total_ability_spanish;
	QStringList total_ability_italian;
	QStringList total_ability_german;
	QStringList total_ability;

	//list with ability ID linked with the ability name
	QStringList pokemon_ability;

	//stores the description and the version o feach pokemon
	QStringList description;

	//stores all the pokemon of one type ineach language
	//so index 0 is english-type1, index 1 is japanese-type1, etc..
	QStringList type_normal;
	QStringList type_fighting;
	QStringList type_flying;
	QStringList type_poison;
	QStringList type_ground;
	QStringList type_rock;
	QStringList type_bug;
	QStringList type_ghost;
	QStringList type_steel;
	QStringList type_fire;
	QStringList type_water;
	QStringList type_grass;
	QStringList type_electric;
	QStringList type_psychic;
	QStringList type_ice;
	QStringList type_dragon;
	QStringList type_dark;
	QStringList type_fairy;

	//the current language represented as an int
	//the current type represented as an int
	int link_language;
	int link_type;

	// Required interface implementation
	virtual int childCount(const QVariantList& indexPath);
	virtual bool hasChildren(const QVariantList& indexPath);
	virtual QVariant data(const QVariantList& indexPath);

	//initializes all the lists and stores all the information
	//all lists are statically allocated
	void init();

	//ability and types function for the stats page
	void abilityTypesStatsPage();

	//sets the langugae and type to the corresponding int value
	void languageChanged(int new_language);
	void typeChanged(int new_type);
	virtual ~PokemonList();
};
#endif /* POKEMONLIST_H_ */

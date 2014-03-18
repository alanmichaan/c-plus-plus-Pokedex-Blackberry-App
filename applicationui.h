#ifndef ApplicationUI_H_
#define ApplicationUI_H_

#include <QObject>
#include <bb/cascades/AbstractPane>

namespace bb
{
    namespace cascades
    {
        class Application;
    }
}

class PokemonList; // forward declaration to avoid including header

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    // callables from QML
    Q_INVOKABLE void typeSelected(int type);
    Q_INVOKABLE void languageSelected(int language);

    virtual ~ApplicationUI() { }
    void Dropdown();
    void languageMenu();
    bb::cascades::AbstractPane *root;
    int current_language;
    int current_type;

    //create two lists: languages in japanese, languages in english
	QStringList languages_english;
	QStringList languages_japanese;
	QStringList languages_german;
	QStringList languages_italian;
	QStringList languages_czech;
	QStringList languages_spanish;
	QStringList languages_french;


	void refreshTypes();
	void initDropdown();

private:
    PokemonList *m_pokemonList;
};


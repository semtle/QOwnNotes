#pragma once

#include <QSqlQuery>
#include <QList>
#include <QJsonObject>
#include <QUrl>
#include <QStringList>

class Script
{
public:
    explicit Script();

    int getId();
    static bool create(QString name, QString scriptPath);
    static Script fetch(int id);
    static Script scriptFromQuery(QSqlQuery query);
    bool store();
    friend QDebug operator<<(QDebug dbg, const Script &script);
    bool exists();
    bool fillFromQuery(QSqlQuery query);
    bool remove();
    bool isFetched();
    static QList<Script> fetchAll(bool enabledOnly = false);
    QString getName();
    QString getScriptPath();
    int getPriority();
    void setName(QString text);
    void setScriptPath(QString text);
    void setPriority(int value);
    static int countAll();
    bool scriptPathExists();
    void setEnabled(bool value);
    bool getEnabled();
    bool isEnabled();
    static int countEnabled();
    void setIdentifier(QString identifier);
    void setInfoJson(QString infoJson);
    QString getIdentifier();
    QJsonObject getInfoJsonObject();
    static QString globalScriptRepositoryPath();
    QString scriptRepositoryPath(bool removeRecursively = false);
    bool isScriptFromRepository();
    QUrl remoteScriptUrl();
    static bool scriptFromRepositoryExists(QString identifier);
    void setSettingsVariablesJson(QString json);
    QJsonObject getSettingsVariablesJsonObject();
    void setSettingsVariablesJson(QJsonObject jsonObject);

private:
    int id;
    QString name;
    QString identifier;
    QString infoJson;
    QString settingsVariablesJson;
    QString scriptPath;
    int priority;
    bool enabled;
};

class ScriptInfoJson {
public:
    explicit ScriptInfoJson(QJsonObject jsonObject);

    QString name;
    QString identifier;
    QString version;
    QString script;
    QString description;
    QStringList richAuthorList;
    QString richAuthorText;
};

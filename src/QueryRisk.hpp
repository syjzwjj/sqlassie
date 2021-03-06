/*
 * SQLassie - database firewall
 * Copyright (C) 2011 Brandon Skari <brandon.skari@gmail.com>
 *
 * This file is part of SQLassie.
 *
 * SQLassie is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SQLassie is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SQLassie. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SRC_QUERYRISK_HPP_
#define SRC_QUERYRISK_HPP_

#include <boost/regex.hpp>
#include <ostream>

/**
 * Stores information about potentionally dangers commands that are found in a
 * parsed query.
 * @author Brandon Skari
 * @date December 6 2010
 */

class QueryRisk
{
public:
    /**
     * Default constructor.
     * @TODO(bskari) This should read configuration from a configuration file.
     */
    QueryRisk();

    QueryRisk(const QueryRisk& rhs);

    enum QueryType
    {
        TYPE_UNKNOWN,
        TYPE_SELECT,
        TYPE_INSERT,
        TYPE_UPDATE,
        TYPE_DELETE,
        TYPE_TRANSACTION,
        TYPE_SET,
        TYPE_EXPLAIN,
        TYPE_SHOW,
        TYPE_DESCRIBE
    };

    enum EmptyPassword
    {
        PASSWORD_NOT_EMPTY = 0,
        PASSWORD_EMPTY = 1,
        PASSWORD_NOT_USED = -1
    };

    // Just as a check for myself, lines marked 'done' are being accounted for
    // and properly increased in either scanner or parser
    /**
     * Risk factors.
     */
    ///@{
    QueryType queryType; // Done
    size_t multiLineComments; // Done
    size_t hashComments; // Done
    size_t dashDashComments; // Done
    size_t mySqlComments; // Done
    size_t mySqlVersionedComments; // Done
    size_t sensitiveTables; // Done
    size_t orStatements; // Done
    size_t unionStatements; // Done
    size_t unionAllStatements; // Done
    size_t bruteForceCommands; // Done
    size_t ifStatements; // Done
    size_t hexStrings; // Done
    size_t benchmarkStatements; // Done
    size_t userStatements; // Done
    size_t fingerprintingStatements; // Done
    size_t mySqlStringConcat; // Done
    size_t stringManipulationStatements; // Done
    size_t alwaysTrueConditional; // Done
    size_t commentedConditionals; // Done
    size_t commentedQuotes; // Done
    size_t globalVariables; // Done
    size_t joinStatements; // Done
    size_t crossJoinStatements;
    size_t regexLength; // Done
    size_t slowRegexes; // Done
    EmptyPassword emptyPassword; // Done
    bool multipleQueries; // Done (not allowed in my parser)
    bool orderByNumber; // Done
    bool alwaysTrue; // Done
    bool informationSchema; // Done
    bool valid;
    bool userTable; // Done
    ///@}

    /**
     * Checks an identifier for a risky identifier and it it is risky, it
     * increments the respective variable.
     */
    ///@{
    void checkTable(const std::string& table);
    void checkFunction(const std::string& function);
    void checkDatabase(const std::string& database);
    ///@}

    /**
     * Checks if a regular expression for denial of service attacks.
     */
    void checkRegex(const std::string& regex);

    friend std::ostream& operator<<(std::ostream& out, const QueryRisk& rhs);
    friend std::ostream& operator<<(std::ostream& out, const QueryType qt);

private:
    static boost::regex sensitiveTablesRegex;
    static boost::regex bruteForceCommandsRegex;
    static boost::regex userStatementsRegex;
    static boost::regex ifRegex;
    static boost::regex benchmarkRegex;
    static boost::regex fingerprintingRegex;
    static boost::regex informationSchemaRegex;
    static boost::regex stringManipulationRegex;
    static const boost::regex userTableRegex;
};


/**
 * Functions needed for boost::hash of ParserInterface::QueryRisk.
 */
/// @{
bool operator==(const QueryRisk& qr1, const QueryRisk& qr2);
size_t hash_value(const QueryRisk& qr);
/// @}

#endif  // SRC_QUERYRISK_HPP_

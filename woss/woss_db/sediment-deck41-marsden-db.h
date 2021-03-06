/* WOSS - World Ocean Simulation System -
 * 
 * Copyright (C) 2009 Federico Guerra
 * and regents of the SIGNET lab, University of Padova
 *
 * Author: Federico Guerra - federico@guerra-tlc.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */ 

/*
 * This software has been developed by Federico Guerra and SIGNET lab,
 * University of Padova, in collaboration with the NATO Centre for 
 * Maritime Research and Experimentation (http://www.cmre.nato.int ; 
 * E-mail: pao@cmre.nato.int), whose support is gratefully acknowledged.
 */


/**
 * @file   sediment-deck41-marsden-db.h
 * @author Federico Guerra
 * 
 * \brief Provides the interface for woss::SedimDeck41MarsdenDb class
 *
 * Provides the interface for the woss::SedimDeck41MarsdenDb class
 */


#ifndef WOSS_SEDIMENT_DECK41_MARSDEN_DB_H 
#define WOSS_SEDIMENT_DECK41_MARSDEN_DB_H


#ifdef WOSS_NETCDF_SUPPORT


#include <sediment-definitions.h>
#include "woss-db.h"
#include "sediment-deck41-coord-db.h"
#if defined (WOSS_NETCDF4_SUPPORT)
#include <ncVar.h>
#endif // defined (WOSS_NETCDF4_SUPPORT)

namespace woss {
  
    
  /**
  * \brief WossDb for custom made NetCDF marsden square DECK41 Sediment database
  *
  * SedimDeck41MarsdenDb implements WossNetcdfDb for the custom made NetCDF marsden square DECK41 Sediment database
  **/
  class SedimDeck41MarsdenDb : public WossNetcdfDb {


    public:

    /**
    * SedimDeck41MarsdenDb constructor.
    * @param name pathname of database
    **/
    SedimDeck41MarsdenDb( const ::std::string& name = DB_NAME_NOT_SET );

#if defined (WOSS_NETCDF4_SUPPORT)
    /**
    * SedimDeck41MarsdenDb constructor.
    * @param name pathname of database
    * @param db_type DECK41 db type
    **/
    SedimDeck41MarsdenDb( const ::std::string& name, DECK41DbType db_type );
#endif // defined (WOSS_NETCDF4_SUPPORT)

    virtual ~SedimDeck41MarsdenDb() { }


    /**
    * Returns a Deck41Types for the given coordinates
    * @param coordinates const reference to a valid Marsden object
    * @returns a Deck41Types value ( main type value, secondary type value )
    **/
    Deck41Types getSeaFloorType( const Marsden& marsden_square ) const; 

    
    /**
    * Checks the validity of SedimDeck41MarsdenDb
    * @return <i>true</i> if pathname is valid, <i>false</i> otherwise
    **/
    virtual bool isValid() { return( WossNetcdfDb::isValid() 
                                      && db_name != DB_NAME_NOT_SET 
                                      && deck41_db_type != DECK41_DB_INVALID_TYPE ); }


    /**
    * Post openConnection() actions, used to create and initialize NetCDF variables
    * @return <i>true</i> if method was successful, <i>false</i> otherwise
    **/
    virtual bool finalizeConnection();

#if defined (WOSS_NETCDF4_SUPPORT)
    /**
    * Sets the current DECK41 Db type
    * @param db_type DECK41DbType 
    **/
    void setDeck41DbType( DECK41DbType db_type ) { deck41_db_type = db_type; }
#endif // defined (WOSS_NETCDF4_SUPPORT)

    /**
     * Returns the current DECK41 DB type
     * @returns current deck41 db type
     */
    DECK41DbType getDeck41DbType() const { return deck41_db_type; }

    
    protected:

    
    /**
    * NetCDF variable representing main DECK41 floortype 
    **/
#if defined (WOSS_NETCDF4_SUPPORT)
    netCDF::NcVar main_sedim_var_marsden;
#else
    NcVar* main_sedim_var_marsden;
#endif // defined (WOSS_NETCDF4_SUPPORT)
    
    /**
    * NetCDF variable representing secondary DECK41 floortype 
    **/
#if defined (WOSS_NETCDF4_SUPPORT)
    netCDF::NcVar sec_sedim_var_marsden;
#else
    NcVar* sec_sedim_var_marsden;
#endif // defined (WOSS_NETCDF4_SUPPORT)
    /**
    * NetCDF marsden square variable
    **/
#if defined(WOSS_NETCDF4_SUPPORT)
    netCDF::NcVar marsden_square_var;
#else
    NcVar* marsden_square_var;
#endif // defined(WOSS_NETCDF4_SUPPORT)

    /**
     * DECK41 database type
     */
    DECK41DbType deck41_db_type;

  };

  
}

#endif // WOSS_NETCDF_SUPPORT

#endif /* WOSS_SEDIMENT_DECK41_MARSDEN_DB_H */

  
 

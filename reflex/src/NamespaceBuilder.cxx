// @(#)root/reflex:$Name:  $:$Id: NamespaceBuilder.cxx,v 1.2 2005/11/03 15:24:40 roiser Exp $
// Author: Stefan Roiser 2004

// Copyright CERN, CH-1211 Geneva 23, 2004-2005, All rights reserved.
//
// Permission to use, copy, modify, and distribute this software for any
// purpose is hereby granted without fee, provided that this copyright and
// permissions notice appear in all copies and derivatives.
//
// This software is provided "as is" without express or implied warranty.

#include "Reflex/Builder/NamespaceBuilder.h"

#include "Reflex/PropertyList.h"
#include "Reflex/Scope.h"

#include "Namespace.h"


//-------------------------------------------------------------------------------
ROOT::Reflex::NamespaceBuilder::NamespaceBuilder( const char * nam ) {
//-------------------------------------------------------------------------------
  Scope sc = Scope::ByName( nam );
  if ( sc && sc.IsNamespace() ) {
    fNamespace       = sc;
  }
  else {
    fNamespace       = (new Namespace( nam ))->ThisScope();
  }
}


//-------------------------------------------------------------------------------
ROOT::Reflex::NamespaceBuilder & 
ROOT::Reflex::NamespaceBuilder::AddProperty( const char * key, 
                                             const char * value ) {
//-------------------------------------------------------------------------------
  fNamespace.Properties().AddProperty( key , value );
  return * this;
}


//-------------------------------------------------------------------------------
ROOT::Reflex::NamespaceBuilder & 
ROOT::Reflex::NamespaceBuilder::AddProperty( const char * key, 
                                             Any value ) {
//-------------------------------------------------------------------------------
  fNamespace.Properties().AddProperty( key , value );
  return * this;
}
    

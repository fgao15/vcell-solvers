// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/layout/CLDefaultStyles.cpp,v $
//   $Revision: 1.2.2.3 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/01/12 19:01:27 $
// End CVS Header

// Copyright (C) 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#include "CLDefaultStyles.h"

#define USE_LAYOUT 1

#ifdef USE_CRENDER_EXTENSION
#define USE_RENDER 1
#endif // USE_CRENDER_EXTENSION

// render includes
#include <sbml/layout/render/GlobalRenderInformation.h>

// xml includes
//
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLNode.h>

/**
 * A pointer to the list of default styles.
 */
CCopasiVector<CLGlobalRenderInformation>* DEFAULT_STYLES = NULL;

const char* DEFAULT_STYLES_STRING = \
                                    "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                                    "<listOfGlobalRenderInformation xmlns=\"http://projects.eml.org/bcb/sbml/render/version1_0_0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">\n"
                                    "  <renderInformation id=\"default\" name=\"blue gradient species glyphs and colored modifiers\"  backgroundColor=\"#FFFFFFFF\">\n"
                                    "    <listOfColorDefinitions>\n"
                                    "      <colorDefinition id=\"speciesColor\" value=\"#D2D2E6\"/>\n"
                                    "      <colorDefinition id=\"compartmentColor\" value=\"#BCCABA\"/>\n"
                                    "      <colorDefinition id=\"white\" value=\"#FFFFFF\"/>\n"
                                    "      <colorDefinition id=\"textColor\" value=\"#000000\"/>\n"
                                    "      <colorDefinition id=\"speciesReferenceColor\" value=\"#4E4E4E\"/>\n"
                                    "      <colorDefinition id=\"frameColor\" value=\"#1A1A1A\"/>\n"
                                    "    </listOfColorDefinitions>\n"
                                    "    <listOfGradientDefinitions>\n"
                                    "      <linearGradient id=\"speciesGlyphGradient\" x1=\"0%\" y1=\"0%\" x2=\"0%\" y2=\"100%\">\n"
                                    "        <stop offset=\"0%\" stop-color=\"white\"/>\n"
                                    "        <stop offset=\"50%\" stop-color=\"speciesColor\"/>\n"
                                    "        <stop offset=\"100%\" stop-color=\"white\"/>\n"
                                    "      </linearGradient>\n"
                                    "      <linearGradient id=\"compartmentGlyphGradient\" x1=\"0%\" y1=\"0%\" x2=\"0%\" y2=\"100%\">\n"
                                    "        <stop offset=\"0%\" stop-color=\"white\"/>\n"
                                    "        <stop offset=\"50%\" stop-color=\"compartmentColor\"/>\n"
                                    "        <stop offset=\"100%\" stop-color=\"white\"/>\n"
                                    "      </linearGradient>\n"
                                    "    </listOfGradientDefinitions>\n"
                                    "    <listOfLineEndings>\n"
                                    "      <lineEnding id=\"ActivationHead\" enableRotationalMapping=\"true\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-2.0\" y=\"-2.0\"/>\n"
                                    "          <dimensions width=\"5.0\" height=\"4.0\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"2.0\" fill=\"none\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"5.0\" y=\"2.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"4.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"2.0\" y=\"2.0\"/>\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"TransitionHead\" enableRotationalMapping=\"true\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-2.0\" y=\"-2.0\"/>\n"
                                    "          <dimensions width=\"5.0\" height=\"4.0\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"1.0\" fill=\"speciesReferenceColor\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"5.0\" y=\"2.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"4.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"2.0\" y=\"2.0\"/>\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"InhibitionHead\" enableRotationalMapping=\"true\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-0.5\" y=\"-3.0\"/>\n"
                                    "          <dimensions width=\"1.0\" height=\"6.0\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"1.0\" fill=\"speciesReferenceColor\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"1.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"1.0\" y=\"6.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"6.0\"/>\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"ModulationHead\" enableRotationalMapping=\"true\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"0.0\" y=\"-2.0\"/>\n"
                                    "          <dimensions width=\"6.0\" height=\"4.0\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"1.0\" fill=\"none\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"2.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"3.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"6.0\" y=\"2.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"3.0\" y=\"4.0\"/>\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "    </listOfLineEndings>\n"
                                    "    <listOfStyles>\n"
                                    "      <style id=\"compartmentGlyphStyle\" typeList=\"COMPARTMENTGLYPH\">\n"
                                    "        <g stroke=\"frameColor\" stroke-width=\"1.0\">\n"
                                    "          <rectangle x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"10%\" ry=\"10%\" fill=\"compartmentGlyphGradient\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"speciesGlyphStyle\" typeList=\"SPECIESGLYPH\">\n"
                                    "        <g stroke=\"frameColor\" stroke-width=\"1.0\">\n"
                                    "          <rectangle x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"10%\" ry=\"10%\" fill=\"speciesGlyphGradient\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"textGlyphStyle\" typeList=\"TEXTGLYPH\">\n"
                                    "        <g stroke=\"textColor\" stroke-width=\"1.0\" font-size=\"20\" text-anchor=\"middle\" font-family=\"sans\"/>\n"
                                    "      </style>\n"
                                    "      <style  id=\"productStyle\" roleList=\"product sideproduct\">\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"2.0\" endHead=\"TransitionHead\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"substrateStyle\" roleList=\"substrate sidesubstrate\" typeList=\"REACTIONGLYPH SPECIESREFERENCEGLYPH\">\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"2.0\" endHead=\"none\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"activatorStyle\" roleList=\"activator\">\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"2.0\" endHead=\"ActivationHead\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"inhibitorStyle\" roleList=\"inhibitor\">\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"2.0\" endHead=\"InhibitionHead\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"modifierStyle\" roleList=\"modifier\">\n"
                                    "        <g stroke=\"speciesReferenceColor\" stroke-width=\"2.0\" endHead=\"ModulationHead\"/>\n"
                                    "      </style>\n"
                                    "    </listOfStyles>\n"
                                    "  </renderInformation>\n"
                                    "  <renderInformation id=\"lightBlue\" name=\"light blue species glyphs and colored modifiers\"  backgroundColor=\"#FFFFFFFF\">\n"
                                    "    <listOfColorDefinitions>\n"
                                    "      <colorDefinition id=\"lightBlue\" value=\"#ADD8E6\"/>\n"
                                    "      <colorDefinition id=\"white\" value=\"#FFFFFF\"/>\n"
                                    "      <colorDefinition id=\"black\" value=\"#000000\"/>\n"
                                    "      <colorDefinition id=\"red\" value=\"#FF0000\"/>\n"
                                    "      <colorDefinition id=\"green\" value=\"#00FF00\"/>\n"
                                    "      <colorDefinition id=\"blue\" value=\"#0000FF\"/>\n"
                                    "      <colorDefinition id=\"lightYellow\" value=\"#FFFFD1\"/>\n"
                                    "      <colorDefinition id=\"darkGreen\" value=\"#002000\"/>\n"
                                    "    </listOfColorDefinitions>\n"
                                    "    <listOfGradientDefinitions>\n"
                                    "      <radialGradient id=\"speciesGlyphGradient\">\n"
                                    "        <stop offset=\"0%\" stop-color=\"white\"/>\n"
                                    "        <stop offset=\"100%\" stop-color=\"lightBlue\"/>\n"
                                    "      </radialGradient>\n"
                                    "    </listOfGradientDefinitions>\n"
                                    "    <listOfLineEndings>\n"
                                    "      <lineEnding id=\"simpleHead_black\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-8\" y=\"-3\"/>\n"
                                    "          <dimensions width=\"10\" height=\"6\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\" fill=\"black\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"10.0\" y=\"3.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"6.0\" />\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"simpleHead_red\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-8\" y=\"-3\"/>\n"
                                    "          <dimensions width=\"10\" height=\"6\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"red\" stroke-width=\"1.0\" fill=\"red\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"10.0\" y=\"3.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"6.0\" />\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"simpleHead_green\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-8\" y=\"-3\"/>\n"
                                    "          <dimensions width=\"10\" height=\"6\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"green\" stroke-width=\"1.0\" fill=\"green\">\n"
                                    "          <polygon>\n"
                                    "             <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"10.0\" y=\"3.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"6.0\" />\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"simpleHead_blue\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-8\" y=\"-3\"/>\n"
                                    "          <dimensions width=\"10\" height=\"6\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"blue\" stroke-width=\"1.0\" fill=\"blue\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"10.0\" y=\"3.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"6.0\" />\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "    </listOfLineEndings>\n"
                                    "    <listOfStyles>\n"
                                    "      <style id=\"compartmentGlyphStyle\" typeList=\"COMPARTMENTGLYPH\">\n"
                                    "        <g stroke=\"darkGreen\" stroke-width=\"1.0\">\n"
                                    "          <rectangle x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"10%\" ry=\"10%\" fill=\"lightYellow\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"speciesGlyphStyle\" typeList=\"SPECIESGLYPH\">\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\">\n"
                                    "          <rectangle x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"5\" ry=\"50%\" fill=\"speciesGlyphGradient\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"reactionGlyphStyle\" typeList=\"REACTIONGLYPH TEXTGLYPH SPECIESREFERENCEGLYPH\">\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\" font-size=\"12\" text-anchor=\"middle\" font-family=\"sans\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"reactantSpeciesReferenceGlyphStyle\" roleList=\"substrate sidesubstrate product sideproduct\">\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\" endHead=\"simpleHead_black\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"activatorSpeciesReferenceGlyphStyle\" roleList=\"activator\">\n"
                                    "        <g stroke=\"green\" stroke-width=\"1.0\" endHead=\"simpleHead_green\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"modifierSpeciesReferenceGlyphStyle\" roleList=\"modifier\">\n"
                                    "        <g stroke=\"blue\" stroke-width=\"1.0\" endHead=\"simpleHead_blue\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"inhibitorSpeciesReferenceGlyphStyle\" roleList=\"inhibitor\">\n"
                                    "        <g stroke=\"red\" stroke-width=\"1.0\" endHead=\"simpleHead_red\"/>\n"
                                    "      </style>\n"
                                    "    </listOfStyles>\n"
                                    "  </renderInformation>\n"
                                    "  <renderInformation id=\"gray_green\" name=\"Gray-Green Default Style\" backgroundColor=\"#FFFFFFFF\">\n"
                                    "    <listOfColorDefinitions>\n"
                                    "      <colorDefinition id=\"SpeciesColorLight\" value=\"#D2D2E6FF\"/>\n"
                                    "      <colorDefinition id=\"CompartmentColorLight\" value=\"#E1F2DFFF\"/>\n"
                                    "      <colorDefinition id=\"SpeciesColorDark\" value=\"#A8A8B8FF\"/>\n"
                                    "      <colorDefinition id=\"CompartmentColorDark\" value=\"#B2BfB0FF\"/>\n"
                                    "      <colorDefinition id=\"ShadowColor\" value=\"#33333399\"/>\n"
                                    "      <colorDefinition id=\"SpeciesReferenceColor\" value=\"#4C4C4CFF\"/>\n"
                                    "      <colorDefinition id=\"FrameColor\" value=\"#191919FF\"/>\n"
                                    "      <colorDefinition id=\"TextColor\" value=\"#000000FF\"/>\n"
                                    "    </listOfColorDefinitions>\n"
                                    "    <listOfGradientDefinitions>\n"
                                    "      <linearGradient id=\"SpeciesGlyphGradient\" x1=\"50%\" y1=\"0%\" x2=\"50%\" y2=\"100%\">\n"
                                    "        <stop offset=\"0%\" stop-color=\"SpeciesColorLight\"/>\n"
                                    "        <stop offset=\"50%\" stop-color=\"SpeciesColorDark\"/>\n"
                                    "        <stop offset=\"100%\" stop-color=\"SpeciesColorLight\"/>\n"
                                    "      </linearGradient>\n"
                                    "      <linearGradient id=\"CompartmentGlyphGradient\" x1=\"50%\" y1=\"0%\" x2=\"50%\" y2=\"100%\">\n"
                                    "        <stop offset=\"0%\" stop-color=\"CompartmentColorLight\"/>\n"
                                    "        <stop offset=\"50%\" stop-color=\"CompartmentColorDark\"/>\n"
                                    "        <stop offset=\"100%\" stop-color=\"CompartmentColorLight\"/>\n"
                                    "      </linearGradient>\n"
                                    "    </listOfGradientDefinitions>\n"
                                    "    <listOfLineEndings>\n"
                                    "      <lineEnding id=\"ActivationHead\" enableRotationalMapping=\"true\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-2.0\" y=\"-2.0\"/>\n"
                                    "          <dimensions width=\"5.0\" height=\"4.0\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"2.0\" fill=\"none\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"5.0\" y=\"2.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"4.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"2.0\" y=\"2.0\"/>\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"TransitionHead\" enableRotationalMapping=\"true\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-2.0\" y=\"-2.0\"/>\n"
                                    "          <dimensions width=\"5.0\" height=\"4.0\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"1.0\" fill=\"SpeciesReferenceColor\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"5.0\" y=\"2.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"4.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"2.0\" y=\"2.0\"/>\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"InhibitionHead\" enableRotationalMapping=\"true\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-0.5\" y=\"-3.0\"/>\n"
                                    "          <dimensions width=\"1.0\" height=\"6.0\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"1.0\" fill=\"SpeciesReferenceColor\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"1.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"1.0\" y=\"6.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"6.0\"/>\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "      <lineEnding id=\"ModulationHead\" enableRotationalMapping=\"true\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"0.0\" y=\"-2.0\"/>\n"
                                    "          <dimensions width=\"6.0\" height=\"4.0\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"1.0\" fill=\"none\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"2.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"3.0\" y=\"0.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"6.0\" y=\"2.0\"/>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"3.0\" y=\"4.0\"/>\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "    </listOfLineEndings>\n"
                                    "    <listOfStyles>\n"
                                    "      <style id=\"compartmentGlyphStyle\" typeList=\"COMPARTMENTGLYPH\">\n"
                                    "        <g>\n"
                                    "          <rectangle stroke=\"FrameColor\" stroke-width=\"1.0\" fill=\"CompartmentGlyphGradient\" x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"10\" ry=\"10\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"speciesGlyphStyle\" typeList=\"SPECIESGLYPH\">\n"
                                    "        <g>\n"
                                    "          <rectangle stroke=\"FrameColor\" stroke-width=\"1.0\" fill=\"SpeciesGlyphGradient\" x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"10\" ry=\"10\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"textGlyphStyle\" typeList=\"TEXTGLYPH\">\n"
                                    "        <g stroke=\"TextColor\" font-family=\"sans-serif\" font-size=\"70%\" text-anchor=\"middle\" vtext-anchor=\"middle\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"productStyle\" roleList=\"product sideproduct\">\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"2.0\" endHead=\"TransitionHead\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"substrateStyle\" roleList=\"substrate sidesubstrate\" typeList=\"REACTIONGLYPH SPECIESREFERENCEGLYPH\">\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"2.0\" endHead=\"none\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"activatorStyle\" roleList=\"activator\">\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"2.0\" endHead=\"ActivationHead\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"inhibitorStyle\" roleList=\"inhibitor\">\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"2.0\" endHead=\"InhibitionHead\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"modifierStyle\" roleList=\"modifier\">\n"
                                    "        <g stroke=\"SpeciesReferenceColor\" stroke-width=\"2.0\" endHead=\"ModulationHead\"/>\n"
                                    "      </style>\n"
                                    "    </listOfStyles>\n"
                                    "  </renderInformation>\n"
                                    "  <renderInformation id=\"grayStyle\" name=\"grayscale style\" backgroundColor=\"#FFFFFFFF\">\n"
                                    "    <listOfColorDefinitions>\n"
                                    "      <colorDefinition id=\"lightGray\" value=\"#CECECE\"/>\n"
                                    "      <colorDefinition id=\"white\" value=\"#FFFFFF\"/>\n"
                                    "      <colorDefinition id=\"black\" value=\"#000000\"/>\n"
                                    "      <colorDefinition id=\"lightGray2\" value=\"#F0F0F0\"/>\n"
                                    "      <colorDefinition id=\"gray\" value=\"#0B0B0B\"/>\n"
                                    "    </listOfColorDefinitions>\n"
                                    "    <listOfGradientDefinitions>\n"
                                    "      <radialGradient id=\"speciesGlyphGradient\">\n"
                                    "        <stop offset=\"0%\" stop-color=\"white\"/>\n"
                                    "        <stop offset=\"100%\" stop-color=\"lightGray\"/>\n"
                                    "      </radialGradient>\n"
                                    "    </listOfGradientDefinitions>\n"
                                    "    <listOfLineEndings>\n"
                                    "      <lineEnding id=\"simpleHead_black\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-8\" y=\"-3\"/>\n"
                                    "          <dimensions width=\"10\" height=\"6\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\" fill=\"black\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"10.0\" y=\"3.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"6.0\" />\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "    </listOfLineEndings>\n"
                                    "    <listOfStyles>\n"
                                    "      <style id=\"compartmentGlyphStyle\" typeList=\"COMPARTMENTGLYPH\">\n"
                                    "        <g stroke=\"gray\" stroke-width=\"1.0\">\n"
                                    "          <rectangle x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"5%\" fill=\"lightGray2\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"speciesGlyphStyle\" typeList=\"SPECIESGLYPH\">\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\">\n"
                                    "          <rectangle x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"5%\" fill=\"speciesGlyphGradient\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"reactionGlyphStyle\" typeList=\"REACTIONGLYPH TEXTGLYPH\">\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\" font-size=\"12\" text-anchor=\"middle\" font-family=\"sans\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"speciesReferenceGlyphStyle\" typeList=\"SPECIESREFERENCEGLYPH\">\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\" endHead=\"simpleHead_black\" />\n"
                                    "      </style>\n"
                                    "    </listOfStyles>\n"
                                    "  </renderInformation>\n"
                                    "  <renderInformation id=\"invertGrayStyle\" name=\"dark grayscale style\" backgroundColor=\"#404040FF\">\n"
                                    "    <listOfColorDefinitions>\n"
                                    "      <colorDefinition id=\"lightGray\" value=\"#CECECE\"/>\n"
                                    "      <colorDefinition id=\"white\" value=\"#FFFFFF\"/>\n"
                                    "      <colorDefinition id=\"black\" value=\"#000000\"/>\n"
                                    "      <colorDefinition id=\"lightGray2\" value=\"#F0F0F0\"/>\n"
                                    "      <colorDefinition id=\"gray\" value=\"#0B0B0B\"/>\n"
                                    "    </listOfColorDefinitions>\n"
                                    "    <listOfGradientDefinitions>\n"
                                    "      <linearGradient id=\"speciesGlyphGradient\">\n"
                                    "        <stop offset=\"0%\" stop-color=\"black\"/>\n"
                                    "        <stop offset=\"5%\" stop-color=\"lightGray\"/>\n"
                                    "        <stop offset=\"50%\" stop-color=\"lightGray2\"/>\n"
                                    "        <stop offset=\"95%\" stop-color=\"lightGray\"/>\n"
                                    "        <stop offset=\"100%\" stop-color=\"black\"/>\n"
                                    "      </linearGradient>\n"
                                    "    </listOfGradientDefinitions>\n"
                                    "    <listOfLineEndings>\n"
                                    "      <lineEnding id=\"simpleHead_white\">\n"
                                    "        <boundingBox>\n"
                                    "          <position x=\"-8\" y=\"-3\"/>\n"
                                    "          <dimensions width=\"10\" height=\"6\"/>\n"
                                    "        </boundingBox>\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\" fill=\"white\">\n"
                                    "          <polygon>\n"
                                    "            <listOfElements>\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"0.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"10.0\" y=\"3.0\" />\n"
                                    "              <element xsi:type=\"RenderPoint\" x=\"0.0\" y=\"6.0\" />\n"
                                    "            </listOfElements>\n"
                                    "          </polygon>\n"
                                    "        </g>\n"
                                    "      </lineEnding>\n"
                                    "    </listOfLineEndings>\n"
                                    "    <listOfStyles>\n"
                                    "      <style id=\"compartmentGlyphStyle\" typeList=\"COMPARTMENTGLYPH\">\n"
                                    "        <g stroke=\"white\" stroke-width=\"1.0\">\n"
                                    "          <rectangle x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"5%\" fill=\"black\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"speciesGlyphStyle\" typeList=\"SPECIESGLYPH\">\n"
                                    "        <g stroke=\"white\" stroke-width=\"1.0\">\n"
                                    "          <rectangle x=\"0%\" y=\"0%\" width=\"100%\" height=\"100%\" rx=\"5%\" fill=\"speciesGlyphGradient\"/>\n"
                                    "        </g>\n"
                                    "      </style>\n"
                                    "      <style id=\"reactionGlyphStyle\" typeList=\"REACTIONGLYPH\">\n"
                                    "        <g stroke=\"white\" stroke-width=\"1.0\" />\n"
                                    "      </style>\n"
                                    "      <style id=\"textGlyphStyle\" typeList=\"TEXTGLYPH\">\n"
                                    "        <g stroke=\"black\" stroke-width=\"1.0\" font-size=\"12\" text-anchor=\"middle\" font-family=\"sans\"/>\n"
                                    "      </style>\n"
                                    "      <style id=\"speciesReferenceGlyphStyle\" typeList=\"SPECIESREFERENCEGLYPH\">\n"
                                    "        <g stroke=\"white\" stroke-width=\"1.0\" endHead=\"simpleHead_white\"/>\n"
                                    "      </style>\n"
                                    "    </listOfStyles>\n"
                                    "  </renderInformation>\n"
                                    "</listOfGlobalRenderInformation>\n"
                                    ;

/**
 * This method returns a global render information list that contains the default styles
 * which are built into the renderer.
 */
CCopasiVector<CLGlobalRenderInformation>* getDefaultStyles()
{
  if (!DEFAULT_STYLES)
    {
      DEFAULT_STYLES = loadDefaultStyles();
    }

  return DEFAULT_STYLES;
}

/**
 * This method returns the number of global styles.
 */
size_t getNumDefaultStyles()
{
  size_t result = 0;

  if (!DEFAULT_STYLES)
    {
      DEFAULT_STYLES = loadDefaultStyles();
    }

  if (DEFAULT_STYLES != NULL)
    {
      result = DEFAULT_STYLES->size();
    }

  return result;
}

/**
 * This method returns the default render information object with
 * the requested index. If the index isinvalid, NULL is returned.
 */
CLGlobalRenderInformation* getDefaultStyle(size_t index)
{
  if (!DEFAULT_STYLES)
    {
      DEFAULT_STYLES = loadDefaultStyles();
    }

  CLGlobalRenderInformation* pResult = NULL;

  if (DEFAULT_STYLES != NULL && index < DEFAULT_STYLES->size())
    {
      pResult = static_cast<CLGlobalRenderInformation*>((*DEFAULT_STYLES)[index]);
    }

  return pResult;
}

CCopasiVector<CLGlobalRenderInformation>* loadDefaultStyles()
{
  // try to initialize the default styles
  if (DEFAULT_STYLES != NULL)
    {
      delete DEFAULT_STYLES;
    }

  XMLInputStream stream(DEFAULT_STYLES_STRING, false);
  ListOfGlobalRenderInformation* pRI = new ListOfGlobalRenderInformation();
  pRI->parseXML(XMLNode(stream));
  // convert the SBML objects to COPASI objects
  size_t i, iMax = pRI->size();
  CCopasiVector<CLGlobalRenderInformation>* pResult = new CCopasiVector<CLGlobalRenderInformation>;

  for (i = 0; i < iMax; ++i)
    {
      pResult->add(new CLGlobalRenderInformation(*static_cast<const GlobalRenderInformation*>(pRI->get((unsigned int) i))));
    }

  return pResult;
}

/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MidiVelAudioProcessorEditor::MidiVelAudioProcessorEditor (MidiVelAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);

	// these define the parameters of our slider object
	midiVolume.setSliderStyle(Slider::Rotary);
	midiVolume.setRange(0.0, 127.0, 1.0);
	midiVolume.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	midiVolume.setPopupDisplayEnabled(true, this);
	midiVolume.setTextValueSuffix(" Velocity");
	midiVolume.setValue(1.0);

	// this function adds the slider to the editor
	addAndMakeVisible(&midiVolume);

	midiVolume.addListener(this);

}

MidiVelAudioProcessorEditor::~MidiVelAudioProcessorEditor()
{
}

//==============================================================================
void MidiVelAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
	g.drawFittedText("Midi Velocity", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void MidiVelAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	midiVolume.setBounds(10, 30, 50, getHeight() - 60);
}

void MidiVelAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    processor.noteOnVel = midiVolume.getValue();
}
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.66666666);
	
	int size = 10;
	for (int x = -150; x <= 150; x += size) {

		for (int y = -400; y <= 400; y += size) {

			for (int z = -150; z <= 150; z += size) {

				auto noise_value = ofNoise(x * 0.003, y * 0.003 + ofGetFrameNum() * 0.03, z * 0.003);
				if (0.47 <= noise_value && noise_value <= 0.53) {

					ofSetColor(255);
					ofFill();
					ofDrawBox(glm::vec3(x, y, z), size * 0.95);

					ofSetColor(0);
					ofNoFill();
					ofDrawBox(glm::vec3(x, y, z), size * 0.95);
				}
			}
		}
	}

	ofDrawBox(300 + size, 800 + size, 300 + size);

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
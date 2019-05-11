#include <unittest++/UnitTest++.h>
#include "/home/user/Documents/SRChandger/SRChandger_cl/SRCclass.h"
#include "/home/user/Documents/SRChandger/SRChandger_cl/SRCclass.cpp"

struct readFixture {
	SampleRateChandger obj;
	int16_t arr[10] = {0,1,2,3,4,5,6,7,8,9};
	char r[4] = {'R','I','F','F'};
	char w[4] = {'W','A','V','E'};
	char f[4] = {'f','m','t',' '};
	char d[4] = {'d','a','t','a'};

	readFixture () {
		ifstream file("/home/user/Downloads/Test.wav");
		obj.read(file);
	}
};

struct erFixture {
	ifstream fr;
	ifstream fw;
	ifstream ff;
	ifstream fc;
	ifstream fSR;
	ifstream fBS;
	ifstream fd;
	erFixture () {
		fr.open("/home/user/Downloads/1.wav");
		fw.open("/home/user/Downloads/2.wav");
		ff.open("/home/user/Downloads/3.wav");
		fc.open("/home/user/Downloads/4.wav");
		fSR.open("/home/user/Downloads/5.wav");
		fBS.open("/home/user/Downloads/6.wav");
		fd.open("/home/user/Downloads/7.wav");
	}

};

struct iFixture {
	SampleRateChandger obj;
	int16_t arrIncreased[19] = {0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9};
	iFixture () {
		ifstream fale("/home/user/Downloads/Test.wav");
		obj.read(fale);
		obj.increase();
	}
};

struct dFixture {
	SampleRateChandger obj;
	int16_t arrDecreased[5] = {0,2,4,6,8};
	dFixture () {
		ifstream fale("/home/user/Downloads/Test.wav");
		obj.read(fale);
		obj.decrease();
	}
};

struct writeFixture {
	SampleRateChandger obj_1;
	SampleRateChandger obj_2;
	int16_t arr[10] = {0,1,2,3,4,5,6,7,8,9};
	char r[4] = {'R','I','F','F'};
	char w[4] = {'W','A','V','E'};
	char f[4] = {'f','m','t',' '};
	char d[4] = {'d','a','t','a'};

	writeFixture () {
		ifstream f("/home/user/Downloads/Test.wav");
		obj_1.read(f);
		f.close();
		ofstream fs("/home/user/Downloads/TestTest.wav");
		obj_1.write(fs);
		fs.close();
		ifstream fl("/home/user/Downloads/TestTest.wav");
		obj_2.read(fl);
		fl.close();
	}
};

SUITE(ReadTest)
{
	TEST_FIXTURE(readFixture, validWav) {
		CHECK_ARRAY_EQUAL(r, obj.getHeaderAdres() -> rID, 4);
		CHECK_EQUAL(56, obj.getHeaderAdres() -> rLen);
		CHECK_ARRAY_EQUAL(w, obj.getHeaderAdres() -> wID, 4);
		CHECK_ARRAY_EQUAL(f, obj.getHeaderAdres() -> Fmt, 4);
		CHECK_EQUAL(16, obj.getHeaderAdres() -> Len);
		CHECK_EQUAL(1, obj.getHeaderAdres() -> Format);
		CHECK_EQUAL(1, obj.getHeaderAdres() -> Channels);
		CHECK_EQUAL(16000, obj.getHeaderAdres() -> SamplesPerSecond);
		CHECK_EQUAL(32000, obj.getHeaderAdres() -> AvgBytesPerSecond);
		CHECK_EQUAL(2, obj.getHeaderAdres() -> BlockAlign);
		CHECK_EQUAL(16, obj.getHeaderAdres() -> BitsPerSample);
		CHECK_ARRAY_EQUAL(d, obj.getHeaderAdres() -> dID, 4);
		CHECK_EQUAL(20, obj.getHeaderAdres() -> dLen);
		CHECK_ARRAY_EQUAL(arr, obj.getValueAdres(), 10);
	}

	TEST_FIXTURE(erFixture, notValidRIFF) {
		CHECK_THROW (SampleRateChandger().read(fr), ErrorWav);
	}
	TEST_FIXTURE(erFixture, notValidWAVE) {
		CHECK_THROW (SampleRateChandger().read(fw), ErrorWav);
	}
	TEST_FIXTURE(erFixture, notValidFMT) {
		CHECK_THROW (SampleRateChandger().read(ff), ErrorWav);
	}
	TEST_FIXTURE(erFixture, notValidCannels) {
		CHECK_THROW (SampleRateChandger().read(fc), ErrorWav);
	}
	TEST_FIXTURE(erFixture, notValidSR) {
		CHECK_THROW (SampleRateChandger().read(fSR), ErrorWav);
	}
	TEST_FIXTURE(erFixture, notValidBperS) {
		CHECK_THROW (SampleRateChandger().read(fBS), ErrorWav);
	}
	TEST_FIXTURE(erFixture, notValidDATA) {
		CHECK_THROW (SampleRateChandger().read(fd), ErrorWav);
	}

}

SUITE(IncreaseTest)
{
	TEST_FIXTURE(iFixture, increase_wav) {
		CHECK_EQUAL(74, obj.getHeaderAdres() -> rLen);
		CHECK_EQUAL(32000, obj.getHeaderAdres() -> SamplesPerSecond);
		CHECK_EQUAL(38, obj.getHeaderAdres() -> dLen);
		CHECK_ARRAY_EQUAL(arrIncreased, obj.getValueAdres(), 19);
	}
}

SUITE(DecreaseTest)
{
	TEST_FIXTURE(dFixture, decrease_wav) {
		CHECK_EQUAL(46, obj.getHeaderAdres() -> rLen);
		CHECK_EQUAL(8000, obj.getHeaderAdres() -> SamplesPerSecond);
		CHECK_EQUAL(10, obj.getHeaderAdres() -> dLen);
		CHECK_ARRAY_EQUAL(arrDecreased, obj.getValueAdres(), 5);
	}
}

SUITE (WriteTest)
{
	TEST_FIXTURE(writeFixture, write_wav) {
		CHECK_ARRAY_EQUAL(obj_1.getHeaderAdres() -> rID, obj_2.getHeaderAdres() -> rID, 4);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> rLen, obj_2.getHeaderAdres() -> rLen);
		CHECK_ARRAY_EQUAL(obj_1.getHeaderAdres() -> wID, obj_2.getHeaderAdres() -> wID, 4);
		CHECK_ARRAY_EQUAL(obj_1.getHeaderAdres() -> Fmt, obj_2.getHeaderAdres() -> Fmt, 4);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> Len, obj_2.getHeaderAdres() -> Len);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> Format, obj_2.getHeaderAdres() -> Format);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> Channels, obj_2.getHeaderAdres() -> Channels);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> SamplesPerSecond, obj_2.getHeaderAdres() -> SamplesPerSecond);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> AvgBytesPerSecond, obj_2.getHeaderAdres() -> AvgBytesPerSecond);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> BlockAlign, obj_2.getHeaderAdres() -> BlockAlign);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> BitsPerSample, obj_2.getHeaderAdres() -> BitsPerSample);
		CHECK_ARRAY_EQUAL(obj_1.getHeaderAdres() -> dID, obj_2.getHeaderAdres() -> dID, 4);
		CHECK_EQUAL(obj_1.getHeaderAdres() -> dLen, obj_2.getHeaderAdres() -> dLen);
		CHECK_ARRAY_EQUAL(obj_1.getValueAdres(), obj_2.getValueAdres(), 10);
	}
}


int main(int argc, char **argv)
{

	return UnitTest::RunAllTests();
}

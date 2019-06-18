/*Тестиравание для модуля Cipher
*Язык прогшраммирования: С++
*Автор: Ольшевская О.И., гр. 18ПИ1
*/
struct Key4_fixture {
Cipher * p;
Key4_fixture() {
p = new Cipher(4);
}
~Key4_fixture() {
delete p;
}
};
SUITE(KeyTest)
{
TEST(ValidKrKey) {
CHECK_EQUAL("qkuxecoohirftubn", Cipher(4).encrypt("thequickbrounfox"));
}
TEST(ValidNotKrKey) {
CHECK_EQUAL("uro*qbf*ekn*hcu*tiox",Cipher(5).encrypt("thequickbrounfox"));
}
TEST(NotIntKey) {
CHECK_EQUAL("qkuxecoohirftubn",Cipher(4.9).encrypt("thequickbrounfox"));
}
TEST(ZeroKey) {
CHECK_THROW(Cipher cp(0),Error);
}
TEST(WeakKey) {
CHECK_THROW(Cipher cp(1),Error);
}
TEST(NegativeKey) {
CHECK_THROW(Cipher cp(-4),Error);
}
}
SUITE(EncryptTest)
{
TEST_FIXTURE(Key4_fixture, UpCaseString) {
CHECK_EQUAL("QKUXECOOHIRFTUBN", p>encrypt("THEQUICKBROUNFOX"));
}
TEST_FIXTURE(Key4_fixture, LowCaseString) {
CHECK_EQUAL("qkuxecoohirftubn", p- >encrypt("thequickbrounfox"));
}
TEST_FIXTURE(Key4_fixture, LowAndUpCaseString) {
CHECK_EQUAL("QkuxecoohirFTuBn", p - >encrypt("TheQuickBrounFox"));
}
TEST_FIXTURE(Key4_fixture, SpaceAndPunctString) {
CHECK_THROW(p->encrypt("the quick broun fox!!!"),Error);
}
TEST_FIXTURE(Key4_fixture, digitString) {
CHECK_THROW(p- >encrypt("the55quickbrounfox"),Error);
}
TEST_FIXTURE(Key4_fixture, EmptyString) {
CHECK_THROW(p->encrypt(""),Error);
}
TEST_FIXTURE(Key4_fixture, noAlphaString) {
CHECK_THROW(p->encrypt("123+123=246"),Error);
}
TEST_FIXTURE(Key4_fixture, ShortString) {
CHECK_THROW(p->encrypt("fox"),Error);
}
TEST_FIXTURE(Key4_fixture, EqualKeyString) {
CHECK_THROW(p->encrypt("pink"),Error);
}
}
SUITE(DecryptTest)
{
TEST_FIXTURE(Key4_fixture, UpCaseString) {
CHECK_EQUAL("THEQUICKBROUNFOX", p- >decrypt("QKUXECOOHIRFTUBN"));
}
TEST_FIXTURE(Key4_fixture, LowCaseString) {
CHECK_EQUAL("thequickbrounfox", p- >decrypt("qkuxecoohirftubn"));
}
TEST_FIXTURE(Key4_fixture, LowAndUpCaseString) {
CHECK_EQUAL("TheQuickBrounFox", p- >decrypt("QkuxecoohirFTuBn"));
}
TEST_FIXTURE(Key4_fixture, PunctString) {
CHECK_THROW(p- >decrypt("qkuxe,coohirftubn"),Error);
}
TEST_FIXTURE(Key4_fixture, digitString) {
CHECK_THROW(p- >decrypt("qkuxecoohirftubn55"),Error);
}
TEST_FIXTURE(Key4_fixture, EmptyString) {
CHECK_THROW(p->decrypt(""),Error);
}
TEST_FIXTURE(Key4_fixture, SpaceString) {
CHECK_THROW(p->decrypt("qkuxe coohirftubn"),Error);
}
TEST_FIXTURE(Key4_fixture, ShortString) {
CHECK_THROW(p->decrypt("fox"),Error);
}
TEST_FIXTURE(Key4_fixture, EqualKeyString) {
CHECK_THROW(p->decrypt("pink"),Error);
}
}
int main(int argc, char **argv)
{
return UnitTest::RunAllTests();
}

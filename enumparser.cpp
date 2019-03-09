#include <clang-c/Index.h>
#include <iostream>


void traverseCursors(CXTranslationUnit translationUnit) {
	CXCursor cursor = clang_getTranslationUnitCursor(translationUnit);
	clang_visitChildren(cursor, [](CXCursor cursor, CXCursor parent, CXClientData clientData) {
		// Visit enum cursors
		if (cursor.kind == CXCursor_EnumConstantDecl) {
	        CXString spelling = clang_getCursorSpelling(cursor);
	        std::cout << "Enum name: " << clang_getCString(spelling) <<
	        ", value: " << clang_getEnumConstantDeclValue(cursor) << std::endl;
	        clang_disposeString(spelling);
		}
		return CXChildVisit_Recurse;
	}, nullptr);
}

int main()
{
	CXIndex index = clang_createIndex(0, 0);
	CXTranslationUnit translationUnit = nullptr;
	CXErrorCode errorCode = clang_parseTranslationUnit2(index,
		"src/fruits.h",
		nullptr, 0,
	    nullptr, 0,
	    CXTranslationUnit_KeepGoing,
		&translationUnit);
	if (translationUnit) {
		std::cout << "Translation unit has been created." << std::endl;
		traverseCursors(translationUnit);
		clang_disposeTranslationUnit(translationUnit);
		clang_disposeIndex(index);
	}
	else {
		std::cerr << "Unable to parse sample file!\nError code:  " << errorCode << std::endl;
	}
}

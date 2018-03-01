/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#pragma once
#include "DeerWinMarco.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "DeerException.h"
#include <string>
#include <tchar.h>


// for granting special access to hWnd only for Graphics constructor
class HWNDKey
{
	friend Graphics::Graphics(HWNDKey&);
public:
	HWNDKey(const HWNDKey&) = delete;
	HWNDKey& operator=(HWNDKey&) = delete;
protected:
	HWNDKey() = default;
protected:
	HWND hWnd = nullptr;
};

class MainWindow : public HWNDKey
{
public:
	class Exception : public DeerException
	{
	public:
		using DeerException::DeerException;
		virtual std::wstring GetFullMessage() const override { return GetNote() + L"\nAt: " + GetLocation(); }
		virtual std::wstring GetExceptionType() const override { return L"Windows Exception"; }
	};
public:
	MainWindow(HINSTANCE hInst, wchar_t* pArgs);
	MainWindow(const MainWindow&) = delete;
	MainWindow& operator=(const MainWindow&) = delete;
	~MainWindow();
	bool IsActive() const;
	bool IsMinimized() const;
	void ShowMessageBox(const std::wstring& title, const std::wstring& message) const;
	void Kill()
	{
		PostQuitMessage(0);
	}
	// returns false if quitting
	bool ProcessMessage();
	const std::wstring& GetArgs() const
	{
		return args;
	}
private:
	static LRESULT WINAPI _HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT WINAPI _HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
public:
	Keyboard kbd;
	Mouse mouse;
private:
	static constexpr wchar_t* wndClassName = _T("Deer DirectX Framework");
	HINSTANCE hInst = nullptr;
	std::wstring args;
};
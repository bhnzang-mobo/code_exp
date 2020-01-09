// ------------------------------------------------------------------------------
// Copyright (c) 2014 Microsoft Corporation
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
// ------------------------------------------------------------------------------

package com.microsoft.onedrivesdk.picker;

import com.microsoft.onedrivesdk.common.*;
import com.microsoft.onedrivesdk.common.TestActivity.*;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import android.test.ActivityUnitTestCase;

import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

import junit.framework.Assert;

/**
 * All test cases for the {@link Picker}
 * 
 * @author pnied
 */
public class PickerTests extends ActivityUnitTestCase<TestActivity> {

    /**
     * The identifier for the APP ID extra within the Picker intent
     */
    private static final String APP_ID_EXTRA = "appId";

    /**
     * The intent action OneDrive Client response to for picking files
     */
    private static final String ONEDRIVE_INTENT_ACTION_PICKER = "onedrive.intent.action.PICKER";

    /**
     * The intent that is used to launch the android market place to download the
     * OneDrive Client
     */
    private static final String ONEDRIVE_ANDROID_MARKET_PLACE_LINK = "market://details?id=com.microsoft.skydrive";

    /**
     * The intent that is used to launch the amazon market place to download the
     * OneDrive Client
     */
    private static final String ONEDRIVE_AMAZON_MARKET_PLACE_LINK = "amzn://apps/android?p=com.microsoft.skydrive";

    /**
     * Default Constructor
     */
    public PickerTests() {
        super(TestActivity.class);
    }

    /**
     * Makes sure that the OneDrive Client is called when we us start picking
     * with the 'app' available.
     */
    public void testStartPickingStartOneDriveClient() {
        // Setup
        final String expectedAppId = "12321";
        final int expectedRequestCode = 987789;
        final TestActivity testActivity = new TestActivity();
        final AtomicInteger queryIntentActivitiesCount = new AtomicInteger();

        testActivity.mQueryIntentActivitiesAction = new QueryIntentActivitiesAction() {
            @Override
            public List<ResolveInfo> action(final Intent intent, final int flags) {
                queryIntentActivitiesCount.incrementAndGet();
                verifyOneDriveGetContentActivity(intent);
                assertEquals(0, flags);
                return Arrays.asList(new ResolveInfo());
            }
        };

        testActivity.mStartActivityForResultAction = new StartActivityForResultAction() {
            @Override
            public void action(final Intent intent, final int requestCode) {
                verifyOneDriveGetContentActivity(intent);
                assertEquals(expectedRequestCode, requestCode);
                assertEquals(expectedAppId, intent.getStringExtra(APP_ID_EXTRA));
            }
        };

        // Action
        final IPicker picker = Picker.createPicker(expectedAppId);
        picker.setRequestCode(expectedRequestCode);
        picker.startPicking(testActivity, LinkType.DownloadLink);

        // Verify
        Assert.assertEquals(0, testActivity.mStartActivityCallCount.get());
        Assert.assertEquals(1, testActivity.mStartActivityForResultCallCount.get());
        Assert.assertEquals(1, queryIntentActivitiesCount.get());
    }

    /**
     * Makes sure that if the OneDrive client is not available we start the
     * android market place link to download it
     */
    public void testStartPickingStartAndroidMarketPlace() {
        // Setup
        final String expectedAppId = "12321";
        final TestActivity testActivity = new TestActivity();
        final AtomicInteger queryIntentActivitiesCount = new AtomicInteger();

        testActivity.mQueryIntentActivitiesAction = new QueryIntentActivitiesAction() {
            @Override
            public List<ResolveInfo> action(final Intent intent, final int flags) {
                queryIntentActivitiesCount.incrementAndGet();
                if (intent.getAction().equals(ONEDRIVE_INTENT_ACTION_PICKER)) {
                    verifyOneDriveGetContentActivity(intent);
                    assertEquals(0, flags);
                    return new ArrayList<ResolveInfo>();
                } else {
                    verifyOneDriveAndroidMarketPlaceActivity(intent);
                    assertEquals(0, flags);
                    return Arrays.asList(new ResolveInfo());
                }
            }
        };

        testActivity.mStartActivityAction = new StartActivityAction() {
            @Override
            public void action(final Intent intent) {
                verifyOneDriveAndroidMarketPlaceActivity(intent);
            }
        };

        // Action
        final IPicker picker = Picker.createPicker(expectedAppId);
        picker.startPicking(testActivity, LinkType.DownloadLink);

        // Verify
        Assert.assertEquals(1, testActivity.mStartActivityCallCount.get());
        Assert.assertEquals(0, testActivity.mStartActivityForResultCallCount.get());
        Assert.assertEquals(2, queryIntentActivitiesCount.get());
    }

    /**
     * Makes sure that if the OneDrive client is not available we start the
     * amazon market place link to download it
     */
    public void testStartPickingStartAmazonMarketPlace() {
        // Setup
        final String expectedAppId = "12321";
        final TestActivity testActivity = new TestActivity();
        final AtomicInteger queryIntentActivitiesCount = new AtomicInteger();

        testActivity.mQueryIntentActivitiesAction = new QueryIntentActivitiesAction() {
            @Override
            public List<ResolveInfo> action(final Intent intent, final int flags) {
                queryIntentActivitiesCount.incrementAndGet();
                if (intent.getAction().equals(ONEDRIVE_INTENT_ACTION_PICKER)) {
                    verifyOneDriveGetContentActivity(intent);
                    assertEquals(0, flags);
                    return new ArrayList<ResolveInfo>();
                } else if (intent.getData().toString().equalsIgnoreCase(ONEDRIVE_ANDROID_MARKET_PLACE_LINK)) {
                    verifyOneDriveAndroidMarketPlaceActivity(intent);
                    assertEquals(0, flags);
                    return new ArrayList<ResolveInfo>();
                } else if (intent.getData().toString().equalsIgnoreCase(ONEDRIVE_AMAZON_MARKET_PLACE_LINK)) {
                    verifyOneDriveAmazonMarketPlaceActivity(intent);
                    assertEquals(0, flags);
                    return Arrays.asList(new ResolveInfo());
                } else {
                    return new ArrayList<ResolveInfo>();
                }
            }
        };

        testActivity.mStartActivityAction = new StartActivityAction() {
            @Override
            public void action(final Intent intent) {
                verifyOneDriveAmazonMarketPlaceActivity(intent);
            }
        };

        // Action
        final IPicker picker = Picker.createPicker(expectedAppId);
        picker.startPicking(testActivity, LinkType.DownloadLink);

        // Verify
        Assert.assertEquals(1, testActivity.mStartActivityCallCount.get());
        Assert.assertEquals(0, testActivity.mStartActivityForResultCallCount.get());
        Assert.assertEquals(3, queryIntentActivitiesCount.get());
    }

    /**
     * Makes sure that if the OneDrive client and the market place isn't
     * installed we show an error message
     */
    public void testStartPickingOnEmulator() {
        // Setup
        final String expectedAppId = "12321";
        final TestActivity testActivity = new TestActivity();
        final AtomicInteger queryIntentActivitiesCount = new AtomicInteger();

        testActivity.mQueryIntentActivitiesAction = new QueryIntentActivitiesAction() {
            @Override
            public List<ResolveInfo> action(final Intent intent, final int flags) {
                queryIntentActivitiesCount.incrementAndGet();
                if (intent.getAction().equals(ONEDRIVE_INTENT_ACTION_PICKER)) {
                    verifyOneDriveGetContentActivity(intent);
                    assertEquals(0, flags);
                    return new ArrayList<ResolveInfo>();
                } else if (intent.getData().toString().equalsIgnoreCase(ONEDRIVE_ANDROID_MARKET_PLACE_LINK)) {
                    verifyOneDriveAndroidMarketPlaceActivity(intent);
                    assertEquals(0, flags);
                    return new ArrayList<ResolveInfo>();
                } else if (intent.getData().toString().equalsIgnoreCase(ONEDRIVE_AMAZON_MARKET_PLACE_LINK)) {
                    verifyOneDriveAmazonMarketPlaceActivity(intent);
                    assertEquals(0, flags);
                    return new ArrayList<ResolveInfo>();
                } else {
                    return new ArrayList<ResolveInfo>();
                }
            }
        };

        testActivity.mStartActivityAction = new StartActivityAction() {
            @Override
            public void action(final Intent intent) {
                verifyOneDriveAndroidMarketPlaceActivity(intent);
            }
        };

        // Action
        final IPicker picker = Picker.createPicker(expectedAppId);
        try {
            picker.startPicking(testActivity, LinkType.DownloadLink);
            fail("Expected error from MockObject");
        } catch (final UnsupportedOperationException e) {
            // Expected
            assertEquals("mock object, not implemented", e.getMessage());
        }

        // Verify
        Assert.assertEquals(0, testActivity.mStartActivityCallCount.get());
        Assert.assertEquals(0, testActivity.mStartActivityForResultCallCount.get());
        Assert.assertEquals(3, queryIntentActivitiesCount.get());
    }

    /**
     * Makes sure that if we have a valid response we can get a picker result
     */
    public void testGetValidPickerResult() {
        // Setup
        final String appId = "12321";
        final int requestCode = 456;
        final IPicker picker = Picker.createPicker(appId);
        picker.setRequestCode(requestCode);

        // Act
        final Intent data = new Intent();
        data.putExtra("linkType", LinkType.DownloadLink.toString());
        data.putExtra("link", Uri.parse("http://foo/bar.txt"));
        final IPickerResult result = picker.getPickerResult(requestCode, Activity.RESULT_OK, data);

        // Verify
        assertNotNull(result);
    }

    /**
     * Makes sure that if we have a request code mismatch we do not get a picker
     * result
     */
    public void testGetPickerResultRequestCodeMismatch() {
        // Setup
        final String appId = "12321";
        final int requestCode = 456;
        final IPicker picker = Picker.createPicker(appId);

        // Act
        final IPickerResult result = picker.getPickerResult(requestCode, Activity.RESULT_OK, new Intent());

        // Verify
        assertNull(result);
    }

    /**
     * Makes sure that if we have a result code failure we do not get a picker
     * result
     */
    public void testGetPickerResultResponseNotOk() {
        // Setup
        final String appId = "12321";
        final int requestCode = 456;
        final IPicker picker = Picker.createPicker(appId);
        picker.setRequestCode(requestCode);

        // Act
        final IPickerResult result = picker.getPickerResult(requestCode, Activity.RESULT_CANCELED, new Intent());

        // Verify
        assertNull(result);
    }

    /**
     * Makes sure the application id is not null when creating the picker
     */
    public void testNullAppIdCreatedPicker() {
        try {
            Picker.createPicker(null);
            fail();
        } catch (final IllegalArgumentException e) {
            assertEquals("appId", e.getMessage());
        }
    }

    /**
     * Makes sure the application id is not empty string when creating the
     * picker
     */
    public void testEmptyAppIdCreatedPicker() {
        try {
            Picker.createPicker("");
            fail();
        } catch (final IllegalArgumentException e) {
            assertEquals("appId", e.getMessage());
        }
    }

    /**
     * Make sure that the given intent matches the expected signature for the
     * action picker
     */
    private void verifyOneDriveGetContentActivity(final Intent intent) {
        assertEquals(ONEDRIVE_INTENT_ACTION_PICKER, intent.getAction());
        assertEquals(Intent.CATEGORY_DEFAULT, intent.getCategories().iterator().next());
    }

    /**
     * Make sure that the given intent matches the expected signature to launch
     * the android market place for OneDrive
     */
    private void verifyOneDriveAndroidMarketPlaceActivity(final Intent intent) {
        assertEquals(Intent.ACTION_VIEW, intent.getAction());
        assertEquals(Uri.parse(ONEDRIVE_ANDROID_MARKET_PLACE_LINK), intent.getData());
    }

    /**
     * Make sure that the given intent matches the expected signature to launch
     * the amazon market place for OneDrive
     */
    private void verifyOneDriveAmazonMarketPlaceActivity(final Intent intent) {
        assertEquals(Intent.ACTION_VIEW, intent.getAction());
        assertEquals(Uri.parse(ONEDRIVE_AMAZON_MARKET_PLACE_LINK), intent.getData());
    }
}
